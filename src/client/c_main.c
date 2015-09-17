/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/17 16:28:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the client's main!
*/

#include "client.h"

static char			*convert_addr(char *s)
{
	if (!ft_strcmp(s, "localhost") || \
		!ft_strcmp(s, "0000:0000:0000:0000:0000:0000:0000:0001") || \
		!ft_strcmp(s, "::1"))
		return (ft_strdup("127.0.0.1"));
	return (s);
}

int					main(int ac, char **av, char **ae)
{
	char		*s;
	t_char		dot;
	t_env		e;

	if (ac != 3)
		error(C_USAGE, *av);
	fill_env(ae, &e, NULL);
	s = av[2];
	ft_istoobig(s) ? error(C_USAGE, *av) : (void)0;
	while (*s)
		ft_isdigit(*s) ? (void)s++ : error(C_USAGE, *av);
	dot = 0;
	av[1] = convert_addr(av[1]);
	s = av[1];
	while (*s)
	{
		if (!ft_isdigit(*s))
			*s == '.' && dot < 3 ? (void)dot++ : error(C_USAGE, *av);
		s++;
	}
	client(av, &e);
	return (EXIT_SUCCESS);
}
