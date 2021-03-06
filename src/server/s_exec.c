/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 05:05:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/18 19:59:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling execution of basics commands (ls, pwd, cd, whoami)
** quit is already handled in the s_read_client function
*/

#include "server.h"

extern int		g_nb;

static char		help(int c)
{
	send_str(" ls      -   list server's current directory\n", c);
	send_str(" cd      -   change server's current directory\n", c);
	send_str(" get     -   copy file from server to client\n", c);
	send_str(" put     -   copy file from client to server\n", c);
	send_str(" pwd     -   show server's current directory\n", c);
	send_str(" quit    -   disconnect and exit\n", c);
	send_str(" cp      -   copy from server to server\n", c);
	send_str(" mv      -   move from server to server\n", c);
	send_str(" rm      -   delete from server\n", c);
	send_str(" mkdir   -   make directory on server\n", c);
	send_str(" cat     -   cat server's file\n", c);
	send_str(" chmod   -   change server's file/dir mod\n", c);
	send_str(" whoami  -   show your client number\n", c);
	send_str(" lls     -   list client's current directory\n", c);
	send_str(" lpwd    -   show client's current directory\n", c);
	send_str(" lcat    -   cat client's file\n", c);
	send_str(" lchmod  -   change client's file/dir mod\n", c);
	send_str(" lcp     -   copy from client to client\n", c);
	send_str(" lmv     -   move from client to client\n", c);
	send_str(" lrm     -   delete from client\n", c);
	send_str(" lmkdir  -   make directory on client\n", c);
	send_str(" lcd     -   change client's current directory\n", c);
	send_str(" help    -   I guess you already found that one\n", c);
	send_str("SUCCESS\n", c);
	return (TRUE);
}

static void		exec_it(char **cmd_tab, int c_fd)
{
	char	*tmp;
	pid_t	pid;

	tmp = ft_strjoin("/bin/", cmd_tab[0]);
	if ((pid = (int)fork()) < 0)
		error(FORK, ft_itoa(pid));
	else if (!pid)
	{
		send_str("cmdstart", c_fd);
		dup2(c_fd, 1);
		dup2(c_fd, 2);
		execv(tmp, cmd_tab);
		error(EXECV, tmp);
	}
	else
		wait4(pid, NULL, 0, NULL);
	*tmp = -42;
	*(tmp + 1) = 0;
	send(c_fd, (void *)tmp, 1, 0);
	ft_memdel((void *)&tmp);
}

static char		exec_builtin(char *cmd, int c_fd)
{
	if (!ft_strcmp(cmd, "whoami"))
	{
		whoami(c_fd);
		send_str("prompt", c_fd);
	}
	else if (!ft_strncmp(cmd, "put", 3) && send_str(cmd, c_fd))
		recv_file(cmd, c_fd);
	else if (!ft_strncmp(cmd, "get", 3))
	{
		if (!is_file(cmd + 4))
		{
			send_str("ERROR\n", c_fd);
			send_str("prompt", c_fd);
			return (TRUE);
		}
		send_str(cmd, c_fd);
		send_file(cmd, c_fd);
	}
	else if (!ft_strcmp(cmd, "help") && help(c_fd))
		send_str("prompt", c_fd);
	else
		return (FALSE);
	return (TRUE);
}

void			exec_cmd(char *cmd, t_env *e, int c_fd)
{
	char	**cmd_tab;

	if (is_local_cmd(cmd))
		send_str(cmd, c_fd);
	else if ((cmd_tab = permission_granted(cmd, e)))
	{
		if (!ft_strncmp("cd", cmd, 2))
		{
			s_cd(cmd_tab, e, c_fd) ? send_str("SUCCESS\n", c_fd) : 0;
			send_str("prompt", c_fd);
		}
		else
			exec_builtin(cmd, c_fd) ? (void)0 : exec_it(cmd_tab, c_fd);
		ft_freestab(cmd_tab);
	}
	else
	{
		send_str("ERROR\naccess denied\n", c_fd);
		send_str("prompt", c_fd);
	}
}
