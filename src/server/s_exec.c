/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 05:05:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/02 20:41:11 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling execution of basics commands (ls, pwd, cd, whoami)
** quit is already handled in the s_read_client function
** TODO: get/put commands
*/

#include "header.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

char    *get_env(char *var, t_env *e)
{
	char    **ae;
	int     i;
	int     len;

	ae = e->ae;
	i = 0;
	len = ft_strlen(var);
	while (ae[i] && ft_strncmp(ae[i], var,
							   (int)ft_strlen(var) > ft_strindex(ae[i], '=') ?
							   (int)ft_strlen(var) : ft_strindex(ae[i], '=')))
		i++;
	return (ae[i] ? ft_strdup(ae[i] + len + 1) : ft_strnew(1));
}

static void		check_cmd(char **cmd, t_env *e)
{
	int		i;
	//char    *tmp;

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

static void		exec_it(char *cmd, t_env *e)
{
	char	**cmd_tab;
	char	*tmp;
	int		save_fd[3];

	save_fd[1] = 1;
	if ((cmd_tab = split_that(cmd)))
	{
		check_cmd(cmd_tab, e);
		tmp = ft_strjoin("/bin/", cmd_tab[0]);
		if ((save_fd[0] = (int)fork()) < 0)
			error(FORK, ft_itoa(save_fd[0]));
		else if (!save_fd[0]) //son... zombie shotgun enough?
		{
			dup2(1, save_fd[1]), dup2(2, save_fd[0]);
			dup2(g_cs[g_nb], 1), dup2(g_cs[g_nb], 2);
			save_fd[2] = execv(tmp, cmd_tab) == -1 ? FALSE : TRUE;
			dup2(save_fd[1], 1), dup2(save_fd[0], 1);
			close(save_fd[1]), close(save_fd[0]);
// the best would be to check if stderr is filled with something,
			//-> if so print ERROR, else SUCCESS
			wait(NULL);
		}
		else
		{
			ft_freestab(cmd_tab);
//		ft_memdel((void *)tmp); LEAK...
			ft_putendl_fd(save_fd[2] ? "SUCCESSS" : "ERRORR", g_cs[g_nb]);
		}
	}
}

void			exec_cmd(char *cmd, t_env *e)
{
	char	**cmd_tab;

	if (!ft_strcmp(cmd, "whoami"))
	{
		ft_putstr_fd("You are the client number ", g_cs[g_nb]);
		ft_putnbr_fd(g_nb, g_cs[g_nb]);
		ft_putendl_fd(".", g_cs[g_nb]);
	}
	else if (!ft_strstr(cmd, "cd"))
		exec_it(cmd, e);
	else if ((cmd_tab = permission_granted(cmd, e)))
	{
		ft_cd(cmd_tab, e, g_cs[g_nb]) ? ft_putendl_fd("SUCCESS", g_cs[g_nb]) : 0;
		ft_freestab(cmd_tab);
	}
}
