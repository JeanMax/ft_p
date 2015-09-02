/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:42:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/02 15:02:34 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle client's reading on stdin/server
*/

#include "client.h"

static t_char	c_read_cmd(int sock)
{
	char		buf[BUFF_SIZE + 1];
	char		*end;
	ssize_t		i;

	while ((i = recv(sock, buf, BUFF_SIZE, 0)) > 0)
	{
		buf[i] = 0;
		if ((end = ft_memchr(buf, -42, (size_t)i)))
		{
			*end = 0;
			ft_putstr(buf);
			ft_putendl("SUCCESS");
			ft_putstr_clr("$Client> ", "g");
			return (1);
		}
		ft_putstr(buf);
	}
	return (0);
}

void			c_read_server(int sock)
{
	char		*line;
	size_t		len;

	line = NULL;
	while ((len = recv_msg(sock, &line)))
	{
		if (!line)
			continue ;
		line[len] = 0;
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (!ft_strcmp(line, "prompt"))
			ft_putstr_clr("$Client> ", "g");
		else if (!ft_strcmp(line, "cmdstart"))
			c_read_cmd(sock);
		else if (!ft_strncmp(line, "get", 3))
			ft_putendl(recv_file(line, sock) ? \
				"SUCCESS" : "ERROR"), ft_putstr_clr("$Client> ", "g");
		else if (ft_strncmp(line, "put", 3))
			ft_putstr(line);
		ft_memdel((void *)&line);
	}
	ft_putendl("Connexion to server closed.");
	line ? ft_memdel((void *)&line) : (void)0;
	close(sock), exit(0);
}

void			c_read_stdin(int sock, t_env *e)
{
	char		*line;

	signal(SIGINT, SIG_IGN);
	line = NULL;
	while (get_line(0, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (!ft_strncmp(line, "put", 3))
			send_str(line, sock), ft_putendl(send_file(line, sock) ? \
				"SUCCESS" : "ERROR"), ft_putstr_clr("$Client> ", "g");
		else if (is_local_cmd(line))
			ft_putstr(exec_local(line, e) ? "SUCCESS\n" : ""), ft_putstr_clr("$Client> ", "g");
		else if (!ft_strncmp(line, "get", 3) || is_cmd(line))
			send_str(line, sock);
		else
			ft_putstr_clr("$Client> ", "g");
		ft_memdel((void *)&line);
	}
	send_str("quit", sock);
	line ? ft_memdel((void *)&line) : (void)0;
	close(sock), exit(0);
}
