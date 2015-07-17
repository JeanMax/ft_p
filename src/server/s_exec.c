/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 05:05:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/17 13:23:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling execution of basics commands (ls, pwd, cd, whoami)
** quit is already handled in the s_read_client function
** TODO: get/put commands
*/

#include "header.h"

extern int		g_nb;
/*
//send file to client
static void		get_file(char *name)
{
int		file_fd;
char	*all;

if ((file_fd = open(name, O_RDONLY)) < 0)
error(OPEN, name);
get_all(file_fd, &all);
send_str(all, g_cs[g_nb]);
close(file_fd);
ft_memdel((void *)&all);
}
*/

 //write client to file
static void		s_put(int c_fd)
{
//	int		file_fd;
	char	line[1024];
	int		i;

	while ((i = (int)read(c_fd, line, 1024)) > 0)
	{
		line[i] = '\0';
		ft_debugstr("line", line); //debug
//		if ((file_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0)
//			error(OPEN, name);
//		send_str(all, file_fd);
//		close(file_fd);
	}
}

char		*get_env(char *var, t_env *e)
{
	char		**ae;
	int			 i;
	size_t		 len;

	ae = e->ae;
	i = 0;
	len = ft_strlen(var);
	while (ae[i] && ft_strncmp(ae[i], var,
							   (int)ft_strlen(var) > ft_strindex(ae[i], '=') ?
							   ft_strlen(var) : (size_t)ft_strindex(ae[i], '=')))
		i++;
	return (ae[i] ? ft_strdup(ae[i] + len + 1) : ft_strnew(1));
}

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

	if ((cmd_tab = split_that(cmd)))
	{
		check_cmd(cmd_tab, e);
		tmp = ft_strjoin("/bin/", cmd_tab[0]);
		send_endl("SUCCESS", c_fd); //wtf
		if ((pid = (int)fork()) < 0)
			error(FORK, ft_itoa(pid));
		else if (!pid) //son... zombie shotgun enough?
		{
			dup2(c_fd, 1), dup2(c_fd, 2);
			execv(tmp, cmd_tab); //check return?
		}
		else
			wait(NULL);
		send_str("promptzboub", c_fd);
		ft_freestab(cmd_tab);
//		ft_memdel((void *)tmp); //LEAK...
	}
}

void			exec_cmd(char *cmd, t_env *e, int c_fd)
{
	char	**cmd_tab;

	if (!ft_strcmp(cmd, "whoami"))
	{
		send_endl("SUCCESS", c_fd);
		send_str("You are the client number ", c_fd);
		ft_putnbr_fd(g_nb, c_fd);
		send_endl(".", c_fd);
		send_str("promptzboub", c_fd);
	}
	else if (!ft_strcmp(cmd, "put"))
		s_put(c_fd);
	else if (!ft_strstr(cmd, "cd"))
		exec_it(cmd, e, c_fd);
	else if ((cmd_tab = permission_granted(cmd, e)))
	{
		ft_cd(cmd_tab, e, c_fd) ? send_endl("SUCCESS", c_fd) : 0;
		ft_freestab(cmd_tab);
		send_str("promptzboub", c_fd);
	}
}
