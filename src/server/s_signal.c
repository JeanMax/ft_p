/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 04:37:42 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "header.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

void			s_sig_handl(int sig)
{
	if (sig == SIGBUS)
		error(BUS, NULL);
	else if (sig == SIGSEGV)
		error(SEG, NULL);
	else if (sig == SIGFPE)
		error (FPE, NULL);
	else if (sig == SIGINT)
	{
		ft_putstr("\b \b\b \bquit");
		sig = 0;
		while (sig <= g_nb)
			g_cs[sig] > 0 ? ft_putendl_fd("quit", g_cs[sig]) : NULL, sig++;
		exit(0);
	}
	else if (sig == 29)
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
