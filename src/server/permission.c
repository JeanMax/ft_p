/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 23:11:31 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 20:28:58 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		check_cmd(char **cmd, t_env *e)
{
	int		i;
	char	*tmp;

	i = -1;
	while (cmd[++i])
		if (cmd[i][0] == '~')
		{
			tmp = cmd[i];
			if (cmd[i][1] != '/')
				cmd[i] = ft_strdup(e->home);
			else
				cmd[i] = ft_strjoin(e->home, cmd[i] + 1);
			ft_memdel((void *)&tmp);
		}
		else if (cmd[i][0] == '$')
		{
			tmp = cmd[i];
			cmd[i] = get_env(cmd[i] + 1, e);
			ft_memdel((void *)&tmp);
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

static t_char	check_path(char **cmd, t_env *e)
{
	char	buf[PATH_SIZE];
	char	*s;

	while (*cmd)
	{
		s = *cmd;
		if (ft_strchr(s, '/') || ft_strstr(s, ".."))
		{
			if (chdir(s))
			{
				while (*s)
					s++;
				s -= *s == '/' ? 2 : 1;
				while (s != *cmd && *s != '/')
					s--;
				if (chdir(s))
					return (0);
			}
			getcwd(buf, PATH_SIZE), chdir(e->pwd);
			if (ft_strncmp(e->path, buf, ft_strlen(e->path)))
				return (0);
		}
		cmd++;
	}
	return (1);
}

char			**permission_granted(char *cmd, t_env *e)
{
	char	**cmd_tab;

	if (!(cmd_tab = split_that(cmd)))
		return (FALSE);
	check_cmd(cmd_tab, e);
	if (!(check_path(cmd_tab, e)))
	{
		chdir(e->pwd); ft_freestab(cmd_tab);
		return (FALSE);
	}
	return (cmd_tab);
}

