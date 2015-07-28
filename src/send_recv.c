/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:20:35 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/29 00:00:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** simple send and receive functions
*/

#include "header.h"

t_char			send_str(char const *str, int fd)
{
	t_char		len;
	size_t		size;

	if (!(size = ft_strlen(str)) || size > 127)
		return (0);
	len = (t_char)size;
	if (send(fd, &len, sizeof(len), 0) == -1)
		return (0);
	return (send(fd, (void *)str, len, 0) != -1 ? 1 : 0);
}

size_t			recv_msg(int const fd, char **msg)
{
	t_char		len;

	len = 0;
	if (recv(fd, &len, sizeof(len), 0) == -1)
		return (0);
	if (!len || len > 127)
		return (0);
	if (!(*msg = (char *)malloc((sizeof(char) * len) + 1)))
		return (0);
	if (recv(fd, *msg, len, 0) == -1)
	{
		*msg ? ft_memdel((void *)msg) : (void)0;
		return (0);
	}
	return (len);
}

static char		*get_file_name(char *s)
{
	while (*s && *s != ' ' && *s != -42)
		s++;
	while (*s && (*s == ' ' || *s == -42))
		s++;
	return (s);
}

//send file to desired fd
t_char			send_file(char *file, int fd)
{
	int			file_fd;
	char		buf[BUFF_SIZE + 1];
	ssize_t		i;

	if ((file_fd = open(get_file_name(file), O_RDONLY)) < 0)
	{
		error(OPEN, get_file_name(file)), send_str("Open failed.\n", fd);
		return (0);
	}
	while ((i = read(file_fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (send(fd, (void *)buf, (size_t)i, 0) == -1)
			return (0);
	}
	*buf = -42;
	*(buf + 1) = -43;
	*(buf + 2) = -44;
	*(buf + 3) = -45;
	*(buf + 4) = 12;
	*(buf + 5) = 0;
	if (send(fd, (void *)buf, 6, 0) == -1)
		return (0);
	close(file_fd);
	return (1);
}

//write msg into a new file
t_char			recv_file(char *file, int fd)
{
	int		file_fd;
	char	buf[BUFF_SIZE + 1];
	ssize_t	i;

	if ((file_fd = open(get_file_name(file),\
						O_WRONLY | O_CREAT | O_APPEND | O_EXCL, 0664)) < 0)

	{
		error(OPEN, get_file_name(file)), send_str("Open failed.\n", fd);
		return (0);
	}
	while ((i = recv(fd, buf, BUFF_SIZE, 0)) > 0)
	{
		buf[i] = 0;
		file = NULL;
		if ((file = ft_memchr(buf, -42, (size_t)i)) && *(file + 1) == -43 \
			&& *(file + 2) == -44 && *(file + 3) == -45 && *(file + 4) == 12)
				{
					write(file_fd, (void *)buf, (size_t)(file - buf));
					break ;
				}
		write(file_fd, (void *)buf, (size_t)i);
	}
	close(file_fd);
	return (1);
}
