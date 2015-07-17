/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:42:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/15 12:20:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle client's reading on stdin/server
*/

#include "header.h"

//send file to server
static void     c_put(char *name, int sock)
{
	int     file_fd;
	char    *all;

	while (*name && *(name - 1) != ' ')
		name++;
	while (*name && *name == ' ')
		name++;
	if ((file_fd = open(name, O_RDONLY)) < 0)
		error(OPEN, name); //do not exit
	get_all(file_fd, &all);
//	ft_debugstr("name", name); //debug
//	ft_debugstr("all", all); //debug
	send_str("put", sock);
	send_str(name, sock);
	send_str("namezboub", sock);
	send_str(all, sock);
	close(file_fd);
	ft_memdel((void *)&all);
}

/*
//write server to file
static void     put_file(char *name, char *all)
{
	int     file_fd;

	if ((file_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0)
		error(OPEN, name);
	send_str(all, file_fd);
	close(file_fd);
}
*/
void				 c_read_stdin(int sock)
{
	char		*line;

	signal(SIGINT, SIG_IGN);
	while (recv_line(0, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (ft_strncmp(line, "ls", 2) && ft_strcmp(line, "pwd") &&	\
				 ft_strncmp(line, "cat", 3) && ft_strncmp(line, "chmod", 5) && \
				 ft_strncmp(line, "cp", 2) && ft_strncmp(line, "mkdir", 5) && \
				 ft_strncmp(line, "mv", 2) && ft_strncmp(line, "rm", 2) && \
				 ft_strncmp(line, "sleep", 5) && ft_strncmp(line, "get", 3) && \
				 ft_strncmp(line, "put", 3) &&							\
				 ft_strncmp(line, "cd", 2) && ft_strcmp(line, "whoami"))
			ft_putstr_clr("$Client> ", "g");
		if (!ft_strncmp(line, "put", 3))
			c_put(line, sock);
		else
			send_endl(line, sock);
		ft_memdel((void *)&line);
	}
	send_endl("42zboubs", sock);
	close(sock), exit(0);
}

void				 c_read_server(int sock)
{
	int			i;
	char		line[1024];
	char		*tmp;

	while ((i = (int)read(sock, line, 1024)) > 0)
	{
		line[i] = '\0';
		if (ft_strstr(line, "42zboubs"))
			break ;
		else if (ft_strstr(line, "promptzboub"))
		{
			if (ft_strlen(line) > 11)
			{
				tmp = line;
				while (*tmp)
					tmp++;
				*(tmp - 12) = '\0';
				ft_putendl(line);
			}
			ft_putstr_clr("$Client> ", "g");
		}
		else if (!ft_strncmp(line, "Server: ", 8))
			ft_putendl(line), ft_putstr_clr("$Client> ", "g");
		else if (ft_strlen(line) > 0)
			ft_putstr(line);
	}
	ft_putendl("Connexion to server closed."), close(sock), exit(0);
}
