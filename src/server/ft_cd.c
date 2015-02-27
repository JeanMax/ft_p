/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 05:54:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 10:26:42 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cd builtin
*/

#include "header.h"

static char		go_to(char *path, t_env *e, int fd)
{
	char		*tmp1;
	char		*tmp2;

	if (path[0] != '/')
	{
		tmp1 = ft_strjoin(e->pwd, "/");
		tmp2 = ft_strjoin(tmp1, path);
		if (chdir(tmp2))
		{
			ft_putstr_fd("ERROR: cd: no such file or directory: ", fd);
			ft_putendl_fd(tmp2, fd);
			ft_memdel((void *)&tmp1), ft_memdel((void *)&tmp2);
			return (FALSE);
		}
		ft_memdel((void *)&tmp1), ft_memdel((void *)&tmp2);
	}
	else if (chdir(path))
	{
		ft_putstr_fd("ERROR: cd: no such file or directory: ", fd);
		ft_putendl_fd(path, fd);
		return (FALSE);
	}
	return (TRUE);
}

char			ft_cd(char **av, t_env *e, int fd)
{
	int		ac;
	char	buf[PATH_SIZE];
	char	ret;

	ac = 0;
	while (av[ac])
		ac++;
	if (ac > 2)
	{
		ft_putendl_fd("ERROR: cd: Too many arguments.", fd);
		return (FALSE);
	}
	else if (ac == 1)
		ret = go_to(e->home, e, fd);
	else if (ac > 1 && !ft_strcmp(av[1], "-"))
		ret = go_to(e->old_pwd, e, fd);
	else
		ret = go_to(av[1], e, fd);
//	ft_memdel((void *)(e->old_pwd)); //la par contre jai pas compris ><
	e->old_pwd = e->pwd; //no free, tout compris :P
	e->pwd = ft_strdup(getcwd(buf, PATH_SIZE));
	return (ret);
}
