/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 20:20:20 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "server.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

void			s_sig_handl(int i)
{
	if (i == SIGBUS)
		error(BUS, NULL);
	else if (i == SIGSEGV)
		error(SEG, NULL);
	else if (i == SIGFPE)
		error(FPE, NULL);
	else if (i == SIGINT)
	{
		i = 0;
		while (i <= g_nb)
		{
			g_cs[i] > 0 ? send_str("quit", g_cs[i]) : 0;
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	else if (i == 29)
		ft_putstr_clr("$Server> ", "g");
}

void			s_sig_init(void)
{
	signal(SIGINT, s_sig_handl);
	signal(SIGFPE, s_sig_handl);
	signal(29, s_sig_handl);
	signal(SIGSEGV, s_sig_handl);
	signal(SIGBUS, s_sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
}
