/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 05:54:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:59:08 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cd builtin
*/

#include "client.h"

static char		go_to(char *path, t_env *e)
{
	char		*tmp1;
	char		*tmp2;

	if (path[0] != '/')
	{
		tmp1 = ft_strjoin(e->pwd, "/");
		tmp2 = ft_strjoin(tmp1, path);
		if (chdir(tmp2))
		{
			failn("ERROR: cd: no such file or directory: ");
			failn(tmp2);
			ft_memdel((void *)&tmp1);
			ft_memdel((void *)&tmp2);
			return (FALSE);
		}
		ft_memdel((void *)&tmp1), ft_memdel((void *)&tmp2);
	}
	else if (chdir(path))
	{
		failn("ERROR: cd: no such file or directory: ");
		failn(path);
		return (FALSE);
	}
	return (TRUE);
}

char			c_cd(char **av, t_env *e)
{
	int		ac;
	char	buf[PATH_SIZE];
	char	ret;

	ac = 0;
	while (av[ac])
		ac++;
	if (ac > 2)
	{
		failn("ERROR: cd: Too many arguments.");
		return (FALSE);
	}
	else if (ac == 1)
		ret = go_to(e->home, e);
	else if (ac > 1 && !ft_strcmp(av[1], "-"))
		ret = go_to(e->old_pwd, e);
	else
		ret = go_to(av[1], e);
	ft_memdel((void *)&(e->old_pwd));
	e->old_pwd = e->pwd;
	e->pwd = ft_strdup(getcwd(buf, PATH_SIZE));
	return (ret);
}
