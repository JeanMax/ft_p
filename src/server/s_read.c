/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:21:12 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 04:43:23 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle server's reading on stdin/client
*/

#include "header.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

void			s_read_stdin(void)
{
	int			 i;
	char		*line;

	//DEBUG; //debug
	signal(SIGINT, s_sig_handl);
	while (get_line(0, &line))
	{
		ft_putstr_clr("$Server> ", "g");
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (ft_strlen(line) > 0)
		{
			i = 0;
			while (i <= g_nb)
				ft_putendl_fd(line, g_cs[i++]);
		}
		ft_memdel((void *)&line);
	}
	i = 0;
	while (i <= g_nb)
		ft_putendl_fd("quit", g_cs[i++]);
	ft_putendl("All clients disconnected.");
	ft_putstr_clr("$Server> ", "g");
	//DEBUG; //debug
}

void			s_read_client(void)
{
	char			*line;

	//DEBUG; //debug
	!g_nb ? ft_putstr_clr("$Server> ", "g"): NULL;
	ft_putstr("Hey "), ft_putnbr(g_nb);
	ft_putstr_clr("\n$Server> ", "g");
	while (get_line(g_cs[g_nb], &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (!ft_strcmp(line, "whoami"))
		{
			ft_putstr_fd("You are the client number ", g_cs[g_nb]);
			ft_putnbr_fd(g_nb, g_cs[g_nb]);
			ft_putendl_fd(".", g_cs[g_nb]);
		}
		else if (ft_strlen(line) > 0)
		{
			ft_putstr("Client "), ft_putnbr(g_nb), ft_putstr(": ");
			ft_putendl(line);
			ft_putstr_clr("$Server> ", "g");
		}
		ft_memdel((void *)&line);
	}
	ft_putendl_fd("quit", g_cs[g_nb]);
	ft_putstr("Bye "), ft_putnbr(g_nb), ft_putstr_clr("\n$Server> ", "g");
	//DEBUG; //debug
}
