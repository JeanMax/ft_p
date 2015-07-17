/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:21:12 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/14 12:16:38 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle server's reading on stdin/client
*/

#include "header.h"

extern int		g_cs[MAX_CLIENTS];
extern int		g_nb;

void			s_read_client(t_env *e)
{
//	char			line[1024];
	char			*line;
//	int				i;
	int				c_fd;

	!g_nb ? ft_putstr_clr("$Server> ", "g"): (void)0;
	ft_putstr("Hey "), ft_putnbr(g_nb);
	ft_putstr_clr("\n$Server> ", "g");
	c_fd = g_cs[g_nb];
	while (recv_line(c_fd, &line))
//	while ((i = read(c_fd, line, 1024)) > 0)	
	{
//		line[i] = '\0';
		ft_debugstr("s_read_line", line); //debug
		if (ft_strstr(line, "42zboubs"))
			break ;
		else if (!ft_strncmp(line, "ls", 2) || !ft_strncmp(line, "pwd", 3) ||\
				 !ft_strncmp(line, "cat", 3) || !ft_strncmp(line, "rm", 3) ||\
				 !ft_strncmp(line, "cp", 2) || !ft_strncmp(line, "mkdir", 5) ||\
				 !ft_strncmp(line, "mv", 2) || !ft_strncmp(line, "chmod", 5) ||\
				 !ft_strncmp(line, "sleep", 5) ||!ft_strncmp(line, "cd", 2) ||\
				 !ft_strncmp(line, "whoami", 6) || \
				 !ft_strncmp(line, "get", 3) || !ft_strncmp(line, "put", 3))
			exec_cmd(line, e, c_fd);
		else if (ft_strlen(line) > 0)
		{
			ft_putstr("Client "), ft_putnbr(g_nb), ft_putstr(": ");
			ft_putendl(line);
			ft_putstr_clr("$Server> ", "g");
		}
//		ft_memdel((void *)&line);
	}
	send_endl("42zboubs", c_fd);
	ft_putstr("Bye "), ft_putnbr(g_nb), ft_putstr_clr("\n$Server> ", "g");
}
