/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 23:24:56 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

void	error(char error, char *msg)
{
	if (error == USAGE)
		fail("Usage: "), fail(msg), failn(USAGE_MSG);
	else if (error == MALLOC)
		fail("Malloc failed with var: "), failn(msg);
	exit(-1);
}
