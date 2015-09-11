/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:57:07 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_p.h"

static void	error_annex(char error, char *msg)
{
	if (error == ACCEPT)
		fail("Accepting connexion failed on sock: ");
	else if (error == CONNECT)
		fail("Connect failed with address: ");
	else if (error == MALLOC)
		fail("Malloc failed with var: ");
	else if (error == PROTO)
		fail("Getprotobyname failed with name: ");
	else if (error == BIND)
		fail("Bind failed with port: ");
	else if (error == FORK)
		fail("Fork failed with pid: ");
	else if (error == OPEN)
		fail("Open failed with file: ");
	else if (error == PATH)
		fail("Invalid minimum folder: ");
	else if (error == KILL)
		fail("Killing stdin_reader process failed with pid: ");
	else if (error == EXECV)
		fail("Execv failed with command: ");
	failn(msg);
}

void		error(char e, char *msg)
{
	if (e == ACCEPT || e == CONNECT || e == MALLOC || e == PROTO || e == BIND \
		|| e == FORK || e == OPEN || e == PATH || e == KILL || e == EXECV)
		error_annex(e, msg);
	else if (e == S_USAGE)
	{
		fail("Usage: ");
		fail(msg);
		failn(S_USAGE_MSG);
	}
	else if (e == C_USAGE)
	{
		fail("Usage: ");
		fail(msg);
		failn(C_USAGE_MSG);
	}
	else if (e == ENV)
		failn("Environment not found.");
	else if (e == BUS)
		failn("Bus error.");
	else if (e == SEG)
		failn("Segmentation fault.");
	else if (e == FPE)
		failn("Floating point exception.");
	e != OPEN ? exit(EXIT_FAILURE) : (void)0;
}
