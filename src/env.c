/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 23:42:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/20 16:42:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mostly some env filling, added some str -> *str function (with env check)
*/

#include "ft_p.h"

void			fill_env(char **ae, t_env *e, char *path)
{
	char    buf[PATH_SIZE];

	if (!*ae)
		error(ENV, NULL);
	e->ae = ae;
	if (!path)
		getcwd(buf, PATH_SIZE), path = buf;
	if (chdir(path))
		error(PATH, path);
	getcwd(buf, PATH_SIZE);
	e->path = ft_strdup(buf);
	e->home = ft_strdup(e->path);
	e->pwd = ft_strdup(e->path);
	e->old_pwd = ft_strdup(e->path);
	if (!(e->home) || !(e->pwd) || !(e->old_pwd) || !(e->path))
		error(ENV, NULL);
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

void		check_cmd(char **cmd, t_env *e)
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

char		**split_that(char *s, t_env *e)
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
