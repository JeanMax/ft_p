/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:55:50 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/12 19:19:18 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Read the first line in the specified file descriptor and fill a given string.
** Return 0 if fail, else 1.
*/

#include "libft.h"
#include <unistd.h>

int	get_line(int const fd, char **a)
{
	int		i;
	int		stop;
	int		n;
	char	buf[BUFF_SIZE];

	if (!a || fd < 0)
		return (0);
	*a = ft_strnew(1);
	n = 0;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		*a = (char *)ft_realloc((void *)*a, ft_strlen(*a), ft_strlen(*a) + i);
		ft_strcat(*a, buf);
		if ((stop = ft_strindex(*a, '\n')) != -1)
		{
			n = 1;
			break ;
		}
	}
	*a = ft_realloc((void *)*a, ft_strlen(*a), stop);
	if (!*a || i < 0 || !n)
		return (0);
	return (1);
}
