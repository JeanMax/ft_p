/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/02 14:18:53 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the server's main!
*/

#include "server.h"

int					main(int ac, char **av, char **ae)
{
	t_env		e;
	char		*s;

	if (ac < 2 || ac > 3)
		error(S_USAGE, av[0]);
	s = av[1];
	if (ft_istoobig(s))
		error(S_USAGE, av[0]);
	while (*s)
	{
		if (!ft_isdigit(*s))
			error(S_USAGE, av[0]);
		s++;
	}
	ac == 3 ? fill_env(ae, &e, av[2]) : fill_env(ae, &e, NULL);
	server(av, &e);
	return (EXIT_SUCCESS);
}
