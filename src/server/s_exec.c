/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 05:05:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 20:14:34 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling execution of basics commands (ls, pwd, cd, whoami)
** quit is already handled in the s_read_client function
*/

#include "header.h"

extern int		g_nb;

static void		check_cmd(char **cmd, t_env *e)
{
	int		i;
	//char	*tmp;

	i = -1;
	while (cmd[++i])
		if (cmd[i][0] == '~')
		{
			//tmp = cmd[i];
			if (cmd[i][1] != '/')
				cmd[i] = ft_strdup(e->home);
			else
				cmd[i] = ft_strjoin(e->home, cmd[i] + 1);
			//ft_memdel((void *)tmp); //LEAAAAAK
		}
		else if (cmd[i][0] == '$')
		{
			//tmp = cmd[i];
			cmd[i] = get_env(cmd[i] + 1, e);
			//ft_memdel((void *)tmp); //LEAAAAAK
		}
}

static char		**split_that(char *s)
{
	int			i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\'')
		{
			s[i] = -42;
			while (s[++i] != '\'')
				if (!s[i])
					return (failn("Unmatched \'."));
			s[i] = -42;
		}
		else if (s[i] == '\"')
		{
			s[i] = -42;
			while (s[++i] != '\"')
				if (!s[i])
					return (failn("Unmatched \"."));
			s[i] = -42;
		}
		else if (s[i] == ' ' || s[i] == '\t')
			s[i] = -42;
	}
	return (ft_strsplit(s, -42));
}

static char		**permission_granted(char *cmd, t_env *e) //TODO
{
	char	**cmd_tab;

	if (!(cmd_tab = split_that(cmd)))
		return (FALSE);
	check_cmd(cmd_tab, e);
	return (cmd_tab);
}

static void		exec_it(char *cmd, t_env *e, int c_fd)
{
	char	**cmd_tab;
	char	*tmp;
	pid_t	pid;
	int		out;
	int		err;

	if (!(cmd_tab = split_that(cmd)))
		return ;
	check_cmd(cmd_tab, e);
	tmp = ft_strjoin("/bin/", cmd_tab[0]); //leak
	if ((out = open("/tmp/1", O_RDWR | O_CREAT | O_TRUNC, 0664)) < 0)
		error(OPEN, "1");
	if ((err = open("/tmp/2", O_RDWR | O_CREAT | O_TRUNC, 0664)) < 0)
		error(OPEN, "2");
	if ((pid = (int)fork()) < 0)
		error(FORK, ft_itoa(pid));
	else if (!pid)
	{
		dup2(out, 1), dup2(err, 2), execv(tmp, cmd_tab);
		error(EXECV, tmp); exit(-1);
	}
	else
		waitpid(pid, NULL, 0); //...
	close(out), close(err);
	if ((out = open("/tmp/1", O_RDONLY)) < 0)
		error(OPEN, "1");
	if ((err = open("/tmp/2", O_RDONLY)) < 0)
		error(OPEN, "2");
	get_all(out, &tmp), send_str(tmp, c_fd); //leak
	get_all(err, &tmp), send_str(tmp, c_fd); //leak
	close(out), close(err), ft_freestab(cmd_tab);
	send_endl(ft_strlen(tmp) ? "ERROR" : "SUCCESS", c_fd);
}

void			exec_cmd(char *cmd, t_env *e, int c_fd)
{
	char	**cmd_tab;

	if (!ft_strcmp(cmd, "whoami"))
		whoami(c_fd);
	else if (!ft_strncmp(cmd, "put", 3))
		send_str(cmd, c_fd), recv_file(cmd, c_fd);
	else if (!ft_strncmp(cmd, "get", 3))
		send_str(cmd, c_fd), send_file(cmd, c_fd);
	else if (!ft_strstr(cmd, "cd"))
		exec_it(cmd, e, c_fd);
	else if ((cmd_tab = permission_granted(cmd, e)))
	{
		ft_cd(cmd_tab, e, c_fd) ? send_endl("SUCCESS", c_fd) : 0;
		ft_freestab(cmd_tab);
	}
	send_str("prompt", c_fd);
}
