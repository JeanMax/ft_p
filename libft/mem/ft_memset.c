/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:57 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:28:32 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  memset()  function  fills  the  first  n  bytes of the memory area
** pointed to by s with the constant byte c.
*/

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	char *swap;

	if (n)
	{
		swap = s;
		while (n--)
			*swap++ = c;
	}
	return (s);
}
