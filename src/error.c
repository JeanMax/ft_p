/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 00:28:54 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

void		error(char error, char *msg)
{
	if (error == USAGE)
		fail("Usage: "), fail(msg), failn(USAGE_MSG);
	else if (error == MALLOC)
		fail("Malloc failed with var: "), failn(msg);
	else if (error == PROTO)
		fail("Getprotobyname failed with name: "), failn(msg);
	else if (error == BIND)
		failn("Bind failed");
	else if (error == ACCEPT)
		fail("Accepting connexion failed on port: "), failn(msg);
	else if (error == CONNECT)
		fail("Connect fail with address: "), failn(msg);
	exit(-1);
}
