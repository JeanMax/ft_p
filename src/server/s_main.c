/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 12:56:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the server's main!
*/

#include "header.h"

int					main(int ac, char **av, char **ae)
{
	t_env			 e;

	if (ac < 2 || ac > 3)
		error(S_USAGE, av[0]);
	ac == 3 ? fill_env(ae, &e, av[2]) : fill_env(ae, &e, NULL);
	server(av, &e);
	return (0);
}
