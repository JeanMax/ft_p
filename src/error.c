/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 20:22:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_p.h"

static void	error_annex(char error, char *msg)
{
	if (error == ACCEPT)
		fail("Accepting connexion failed on sock: "), failn(msg);
	else if (error == CONNECT)
		fail("Connect failed with address: "), failn(msg);
	else if (error == MALLOC)
		fail("Malloc failed with var: "), failn(msg);
	else if (error == PROTO)
		fail("Getprotobyname failed with name: "), failn(msg);
	else if (error == BIND)
		fail("Bind failed with port: "), failn(msg);
	else if (error == FORK)
		fail("Fork failed with pid: "), failn(msg);
	else if (error == BUS)
		failn("Bus error.");
	else if (error == SEG)
		failn("Segmentation fault.");
	else if (error == FPE)
		failn("Floating point exception.");
}

void		error(char e, char *msg)
{
	if (e == ACCEPT || e == CONNECT || e == MALLOC || e == PROTO || \
		e == BIND || e == FORK || e == BUS || e == SEG || e == FPE)
		error_annex(e, msg);
	else if (e == S_USAGE)
		fail("Usage: "), fail(msg), failn(S_USAGE_MSG);
	else if (e == C_USAGE)
		fail("Usage: "), fail(msg), failn(C_USAGE_MSG);
	else if (e == KILL)
		fail("Killing stdin_reader process failed with pid: "), failn(msg);
	else if (e == EXECV)
		fail("Execv failed with command: "), failn(msg);
	else if (e == ENV)
		failn("Environment not found.");
	else if (e == OPEN)
		fail("Open failed with file: "), failn(msg);
	else if (e == PATH)
		fail("Invalid minimum folder: "), failn(msg);
	e != OPEN ? exit(-1) : (void)0;
}
