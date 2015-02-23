/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:37:18 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:46:28 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  bzero()  function sets the first n bytes of the area starting at s
** to zero (bytes containing '\0').
*/

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	char *swap;

	if (n)
	{
		swap = s;
		while (n--)
			*swap++ = 0;
	}
}
