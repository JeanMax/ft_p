/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/02 14:19:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the client's main!
*/

#include "client.h"

int					main(int ac, char **av, char **ae)
{
	char		*s;
	t_char		dot;
	t_env		e;

	if (ac != 3)
		error(C_USAGE, av[0]);
	fill_env(ae, &e, NULL);
	s = av[2];
	ft_istoobig(s) ? error(C_USAGE, av[0]) : (void)0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			error(C_USAGE, av[0]);
		s++;
	}
	dot = 0;
	av[1] = ft_strcmp(av[1], "localhost") ? av[1] : ft_strdup("127.0.0.1"); //leak
	s = av[1];
	while (*s)
	{
		if (!ft_isdigit(*s))
			*s == '.' && dot < 3 ? (void)dot++ : error(C_USAGE, av[0]);
		s++;
	}
	client(av, &e);
	return (EXIT_SUCCESS);
}
