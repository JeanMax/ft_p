/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:20:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 00:39:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!
*/

#include "header.h"

int					main(int ac, char **av)
{
	//t_env			 *e; //TODO

	if (ac == 3)
		client(av);
	else if (ac == 2)
		server(av);
	else
		error(USAGE, av[0]);
	return (0);
}
