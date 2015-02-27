/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:42:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 08:52:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle client's reading on stdin/client
*/

#include "header.h"

void				 c_read_stdin(int sock)
{
	char		*line;

	signal(SIGINT, SIG_IGN);
	while (get_line(0, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (!ft_strstr(line, "ls") && ft_strcmp(line, "pwd") && \
				 !ft_strstr(line, "cd") && ft_strcmp(line, "whoami"))
			ft_putstr_clr("$Client> ", "g"); //find better than strstr
		ft_putendl_fd(line, sock);
		ft_memdel((void *)&line);
	}
	ft_putendl_fd("quit", sock);
	close(sock), exit(0);
}

void				 c_read_server(int sock)
{
	int			i;
	char		buf[1024];

	while ((i = read(sock, buf, 1024)) > 0)
	{
		buf[i] = '\0';
		if (ft_strstr(buf, "quit"))
			break ;
		else if (ft_strstr(buf, "Server: "))
			ft_putendl(buf), ft_putstr_clr("$Client> ", "g");
		else if (ft_strlen(buf) > 0)
			ft_putstr(buf);
		if  (ft_strcmp(buf, "ERROR") && ft_strcmp("SUCCESS", buf) && \
			 ft_strchr(buf, '\n'))
			ft_putstr_clr("$Client> ", "g");
	}
	ft_putendl("Connexion to server closed."), close(sock), exit(0);
}
