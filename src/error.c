/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 13:38:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

void		error(char error, char *msg) //free itoa? //do not exit everytime
{
	if (error == S_USAGE)
		fail("Usage: "), fail(msg), failn(S_USAGE_MSG);
	else if (error == C_USAGE)
		fail("Usage: "), fail(msg), failn(C_USAGE_MSG);
	else if (error == MALLOC)
		fail("Malloc failed with var: "), failn(msg);
	else if (error == PROTO)
		fail("Getprotobyname failed with name: "), failn(msg);
	else if (error == BIND)
		fail("Bind failed with port: "), failn(msg);
	else if (error == ACCEPT)
		fail("Accepting connexion failed on sock: "), failn(msg);
	else if (error == CONNECT)
		fail("Connect failed with address: "), failn(msg);
	else if (error == FORK)
		fail("Fork failed with pid: "), failn(msg);
	else if (error == BUS)
		failn("Bus error.");
	else if (error == SEG)
		failn("Segmentation fault.");
	else if (error == FPE)
		failn("Floating point exception.");
	else if (error == KILL)
		fail("Killing stdin_reader process failed with pid: "), failn(msg);
	else if (error == EXECV)
		fail("Execv failed with command: "), failn(msg);
	else if (error == ENV)
		failn("Environment not found.");
	else if (error == OPEN)
		fail("Open failed with file: "), failn(msg);
	else if (error == PATH)
		fail("Invalid allowed-path: "), failn(msg);
	error != OPEN ? exit(-1) : (void)0;
}
