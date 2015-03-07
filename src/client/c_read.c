/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:42:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/07 20:17:48 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle client's reading on stdin/server
*/

#include "header.h"
/*
//send file to server
static void     get_file(char *name, int sock)
{
	int     file_fd;
	char    *all;

	while (*name && *(name - 1) != ' ')
		name++;
	while (*name && *name == ' ')
		name++;
	if ((file_fd = open(name, O_RDONLY)) < 0)
		error(OPEN, name);
	get_all(file_fd, &all);
	ft_putstr_fd(all, sock);
	close(file_fd);
	ft_memdel((void *)&all);
}

//write server to file
static void     put_file(char *name, char *all)
{
	int     file_fd;

	if ((file_fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0)
		error(OPEN, name);
	ft_putstr_fd(all, file_fd);
	close(file_fd);
}
*/
void				 c_read_stdin(int sock)
{
	char		*line;

	signal(SIGINT, SIG_IGN);
	while (get_line(0, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (!ft_strstr(line, "ls") && ft_strcmp(line, "pwd") && \
				 !ft_strstr(line, "cat") && !ft_strstr(line, "chmod") && \
				 !ft_strstr(line, "cp") && !ft_strstr(line, "mkdir") && \
				 !ft_strstr(line, "mv") && !ft_strstr(line, "rm") && \
				  !ft_strstr(line, "sleep") && !ft_strstr(line, "get") && \
				 !ft_strstr(line, "put") && \
				 !ft_strstr(line, "cd") && ft_strcmp(line, "whoami"))
			ft_putstr_clr("$Client> ", "g"); //find better than strstr
		ft_putendl_fd(line, sock);
//		if (!ft_strstr(line, "put"))
//			get_file(line, sock);
		ft_memdel((void *)&line);
	}
	ft_putendl_fd("quit", sock);
	close(sock), exit(0);
}

void				 c_read_server(int sock)
{
	int			i;
//	char		*line;
	char		buf[1024];

	while ((i = read(sock, buf, 1024)) > 0)
//	while (get_line(sock, &line))
	{
		buf[i] = '\0';
//		if (ft_strstr(buf, "quit")) //files in ls can have "quit" in their names...
//			break ;
		if (ft_strstr(buf, "Server: "))
			ft_putendl(buf), ft_putstr_clr("$Client> ", "g");
		else if (ft_strlen(buf) > 0)
			ft_putstr(buf);
		if  (ft_strcmp(buf, "ERROR") && ft_strcmp("SUCCESS", buf) && \
			 ft_strchr(buf, '\n'))
			ft_putstr_clr("$Client> ", "g");
	}
	ft_putendl("Connexion to server closed."), close(sock), exit(0);
}
