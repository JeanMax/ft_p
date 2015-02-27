/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 10:22:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the server's main!
*/

#include "header.h"

static void			fill_env(char **ae, t_env *e, char *stop)
{
	e->ae = ae;
	while (*ae)
	{
		if (ft_strstr(*ae, "HOME="))
			e->home = ft_strdup(*ae + 5);
		else if (ft_strstr(*ae, "OLDPWD="))
			e->old_pwd = ft_strdup(*ae + 7);
		else if (ft_strstr(*ae, "PWD="))
			e->pwd = ft_strdup(*ae + 4);
		ae++;
	}
	e->stop = stop ? stop : e->pwd;
	if (!(e->home) || !(e->pwd) || !(e->old_pwd) || !(e->stop))
		error(ENV, NULL);
}

int					main(int ac, char **av, char **ae)
{
	t_env			 e;

	if (ac < 2 || ac > 3)
		error(S_USAGE, av[0]);
	ac == 3 ? fill_env(ae, &e, av[2]) : fill_env(ae, &e, NULL);
	server(av, &e);
	return (0);
}
