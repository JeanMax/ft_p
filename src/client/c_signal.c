/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:39:03 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/27 11:18:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place where signals are handled!
*/

#include "client.h"

static void		c_sig_handl(int sig)
{
	if (sig == SIGBUS)
		error(BUS, NULL);
	else if (sig == SIGSEGV)
		error(SEG, NULL);
	else if (sig == SIGFPE)
		error(FPE, NULL);
	else if (sig == SIGINT)
	{
		ft_putstr("\b \b\b \b\n");
		ft_putstr_clr("$Client> ", "g");
	}
	else if (sig == 29)
		ft_putstr_clr("$Client> ", "g");
}

void			c_sig_init(void)
{
	signal(SIGINT, c_sig_handl);
	signal(SIGFPE, c_sig_handl);
	signal(29, c_sig_handl);
	signal(SIGSEGV, c_sig_handl);
	signal(SIGBUS, c_sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
}
