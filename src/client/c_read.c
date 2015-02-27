/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:42:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 04:44:08 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle client's reading on stdin/client
*/

#include "header.h"

void				 c_read_stdin(char *line, int sock)
{
	signal(SIGINT, SIG_IGN);
	while (get_line(0, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		ft_putstr_clr("$Client> ", "g");
		ft_putendl_fd(line, sock);
		ft_memdel((void *)&line);
	}
	ft_putendl_fd("quit", sock);
	close(sock), exit(0);
}

void				 c_read_server(char *line, int sock)
{
	while (get_line(sock, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		ft_putstr("Server: "), ft_putendl(line);
		ft_putstr_clr("$Client> ", "g");
		ft_memdel((void *)&line);
	}
	ft_putendl("Connexion to server closed."), close(sock), exit(0);
}
