/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/17 13:22:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "header.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

void			s_sig_handl(int i)
{
	if (i == SIGBUS)
		error(BUS, NULL);
	else if (i == SIGSEGV)
		error(SEG, NULL);
	else if (i == SIGFPE)
		error (FPE, NULL);
	else if (i == SIGINT)
	{
		ft_putstr("\b \b\b \bquit");
		i = 0;
		while (i <= g_nb)
			g_cs[i] > 0 ? send_endl("42zboubs", g_cs[i]) : 0, i++;
		exit(0);
	}
	else if (i == 29)
		ft_putstr_clr("$Server> ", "g");
}

void			s_sig_init(void)
{
	signal(SIGFPE, s_sig_handl);
	signal(29, s_sig_handl);
	signal(SIGSEGV, s_sig_handl);
	signal(SIGBUS, s_sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGCHLD, SIG_IGN); //testing! zombie shotgun
}
