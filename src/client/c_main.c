/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 19:59:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the client's main!
*/

#include "header.h"

int					main(int ac, char **av)
{
	char		*s;
	t_char		dot;

	if (ac != 3)
		error(C_USAGE, av[0]);
	s = av[2];
	ft_istoobig(s) ? error(C_USAGE, av[0]) : (void)0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			error(C_USAGE, av[0]);
		s++;
	}
	dot = 0;
	s = av[1];
	if (!ft_strcmp(s, "localhost"))
		av[1] = ft_strdup("127.0.0.1");
	while (*s)
	{
		if (!ft_isdigit(*s))
			*s == '.' && dot < 3 ? (void)dot++ : error(C_USAGE, av[0]);
		s++;
	}
	client(av);
	return (0);
}
