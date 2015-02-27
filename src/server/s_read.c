/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:21:12 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 08:06:32 by mcanal           ###   ########.fr       */
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
	char		*tmp;

	signal(SIGINT, s_sig_handl);
	while (get_line(0, &line))
	{
		i = 0;
		ft_putstr_clr("$Server> ", "g");
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (ft_strlen(line) > 0)
			while (i <= g_nb)
				tmp = ft_strjoin("Server: ", line), \
					ft_putstr_fd(tmp, g_cs[i++]), ft_memdel((void *)&tmp);
		ft_memdel((void *)&line);
	}
	i = 0;
	while (i <= g_nb)
		ft_putendl_fd("quit", g_cs[i++]);
	ft_putendl("All clients disconnected.");
	ft_putstr_clr("$Server> ", "g");
}

void			s_read_client(t_env *e)
{
	char			*line;

	!g_nb ? ft_putstr_clr("$Server> ", "g"): NULL;
	ft_putstr("Hey "), ft_putnbr(g_nb);
	ft_putstr_clr("\n$Server> ", "g");
	while (get_line(g_cs[g_nb], &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (ft_strstr(line, "ls") || !ft_strcmp(line, "pwd") || \
				 ft_strstr(line, "cd") || !ft_strcmp(line, "whoami"))
			exec_cmd(line, e); //find better than strstr
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
}
