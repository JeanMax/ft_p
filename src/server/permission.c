/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 23:11:31 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/18 19:05:54 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** May the client access this location? that's the question
*/

#include "server.h"

static t_char	check_that_path(char *cmd, t_env *e)
{
	char	buf[PATH_SIZE];
	char	*s;

	s = cmd;
	if (ft_strchr(s, '/') || ft_strstr(s, ".."))
	{
		if (chdir(s))
		{
			while (*s)
				s++;
			s -= (*s - 1) == '/' ? 2 : 1;
			while (s != cmd && *s != '/')
				s--;
			*buf = *s;
			*s = 0;
			if (chdir(cmd))
				return (FALSE);
			*s = *buf;
		}
		if (getcwd(buf, PATH_SIZE) && !chdir(e->pwd) && \
			ft_strncmp(e->path, buf, ft_strlen(e->path)))
			return (FALSE);
	}
	return (TRUE);
}

static t_char	check_path(char **cmd, t_env *e)
{
	while (*cmd)
	{
		if (!check_that_path(*cmd, e))
			return (FALSE);
		cmd++;
	}
	return (TRUE);
}

char			**permission_granted(char *cmd, t_env *e)
{
	char	**cmd_tab;

	if (!(cmd_tab = split_that(cmd)))
		return (FALSE);
	check_cmd(cmd_tab, e);
	if (!(check_path(cmd_tab, e)))
	{
		chdir(e->pwd);
		ft_freestab(cmd_tab);
		return (FALSE);
	}
	return (cmd_tab);
}
