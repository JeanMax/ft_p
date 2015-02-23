/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:44 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:28:16 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  memmove()  function  copies n bytes from memory area src to memory
** area dest.  The memory areas may overlap: copying takes place as though
** the  bytes in src are first copied into a temporary array that does not
** overlap src or dest, and the bytes are then copied from  the  temporary
** array to dest.
*/

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	void	*swap[n];

	ft_memcpy(swap, src, n);
	ft_memcpy(dest, swap, n);
	return (dest);
}
