/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:21:12 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/27 11:13:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle server's reading	on stdin/client
*/

#include "server.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

static void		say_hey(void)
{
	if (!g_nb)
		ft_putstr_clr("$Server> ", "g");
	ft_putstr("Hey ");
	ft_putnbr(g_nb);
	ft_putstr_clr("\n$Server> ", "g");
}

static void		say_cmd(char *line)
{
	ft_putstr("Client ");
	ft_putnbr(g_nb);
	ft_putstr(": ");
	ft_putendl(line);
	ft_putstr_clr("$Server> ", "g");
}

static void		say_bye(void)
{
	send_str("quit", g_cs[g_nb]);
	ft_putstr("Bye ");
	ft_putnbr(g_nb);
	ft_putstr_clr("\n$Server> ", "g");
}

void			s_read_client(t_env *e)
{
	char			*line;
	size_t			len;

	say_hey();
	line = NULL;
	while (TRUE)
	{
		len = recv_msg(g_cs[g_nb], &line);
		if (!line || !len)
			continue ;
		line[len] = 0;
		if (!ft_strcmp(line, "quit"))
			break ;
		if (is_cmd(line))
		{
			say_cmd(line);
			exec_cmd(line, e, g_cs[g_nb]);
		}
		ft_memdel((void *)&line);
	}
	ft_memdel((void *)&line);
	say_bye();
}
