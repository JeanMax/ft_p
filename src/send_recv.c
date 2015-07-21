/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:20:35 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 16:17:44 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** simple send and receive functions
*/

#include "header.h"

t_char			send_str(char const *str, int fd)
{
	size_t		len;

	if (!(len = ft_strlen(str)))
		return (0);
	if (send(fd, &len, sizeof(len), 0) == -1)
		return (0);
	return (send(fd, (void *)str, len, 0) != -1 ? 1 : 0);
}

t_char			send_endl(char const *str, int fd)
{
	size_t		len;

	len = ft_strlen(str) + 1;
	if (send(fd, &len, sizeof(len), 0) == -1)
		return (0);
	if (len > 1)
		if (send(fd, (void *)str, len - 1, MSG_MORE) == -1)
			return (0);
	return (send(fd, (void *)"\n", 1, 0) != -1 ? 1 : 0);
}

size_t			recv_msg(int const fd, char **msg)
{
	size_t		len;

	len = 0;
	if (recv(fd, &len, sizeof(len), 0) == -1)
		return (0);
	if (!len)
		return (0);
	if (!(*msg = (char *)malloc((sizeof(char) * len) + 1)))
		return (0);
	if (recv(fd, *msg, len, 0) == -1)
		return (0);
	return (len);
}

//send file to desired fd
t_char		 send_file(char *file, int fd)
{
	int			file_fd;
	char		buf[BUFF_SIZE + 1];
	ssize_t		i;

	while (*file && *file != ' ')
		file++;
	while (*file && *file == ' ')
		file++;
	if ((file_fd = open(file, O_RDONLY)) < 0)
		error(OPEN, file), send_str("Open failed.", fd);
	while ((i = read(file_fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!send_str(buf, fd))
			return (0);
	}
	*file = -42;
	*(file + 1) = 0;
	if (!send_str(file, fd))
		return (0);
	close(file_fd);
	return (1);
}

//write msg into a new file
t_char		recv_file(char *file, int fd)
{
	int		file_fd;
	char	*msg;
	size_t	len;

	msg = NULL;
	while (*file && *file != ' ')
		file++;
	while (*file && *file == ' ')
		file++;
	*file = 'z'; //debug
	if ((file_fd = open(file, \
						O_WRONLY | O_CREAT | O_APPEND | O_EXCL, 0664)) < 0)
		error(OPEN, file), send_str("Open failed.", fd);
	while (1)
	{
		if (!(len = recv_msg(fd, &msg)))
			return (0);
		msg[len] = 0;
		if (*msg == -42 && len == 1)
			break ;
		ft_putstr_fd(msg, file_fd);
		ft_memdel((void *)&msg);	
	}
	close(file_fd);
	return (1);
}
