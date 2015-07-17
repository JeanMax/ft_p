/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:20:35 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/15 12:48:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** simple send and receive functions
** equivalent to putstr_fd and get_line
*/

#include "header.h"

t_char			send_str(char const *str, int fd)
{
	return (send(fd, (void *)str, ft_strlen(str), 0) != -1 ? 1 : 0);
}

t_char			send_endl(char const *str, int fd)
{
	send(fd, (void *)"\n", 1, 0);
	return (send(fd, (void *)str, ft_strlen(str), 0) != -1 ? 1 : 0);
}

t_char			recv_line(int const fd, char **line)
{
	ssize_t	i;
	int		stop;
	int		n;
	char	buf[BUFF_SIZE];

	if (!line || fd < 0)
		return (0);
	*line = ft_strnew(1);
	n = 0;
	while ((i = recv(fd, (void *)buf, BUFF_SIZE, 0)) > 0)
	{
		buf[i] = '\0';
		*line = (char *)ft_realloc(\
			(void *)*line, ft_strlen(*line), ft_strlen(*line) + (size_t)i);
		ft_strcat(*line, buf);
		if ((stop = ft_strindex(*line, '\n')) != -1)
		{
			n = 1;
			break ;
		}
	}
	*line = ft_realloc((void *)*line, ft_strlen(*line), (size_t)stop);
	if (!*line || i < 0 || !n)
		return (0);
	return (1);
}


