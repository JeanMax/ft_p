/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:41:46 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:17:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The `ft_strlcat()` function concatenates the null-terminated string `src`
** into the null-terminated string `dst`. The `size` parameter represents a
** buffer size (= big), not a combined strings' size like that of `ft_strncat`.
** If copy cannot occur because buffer's `size` is too small, returns
** `size + ft_strlen(src)`; otherwise, perform the copy and returns final size.
*/

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dest_swap;
	char			*src_swap;
	unsigned int	size_swap;
	unsigned int	dest_len;

	dest_swap = dest;
	src_swap = (char *)src;
	size_swap = size;
	while (size_swap-- && *dest_swap)
		dest_swap++;
	dest_len = dest_swap - dest;
	size_swap = size - dest_len;
	if (size_swap == 0)
		return (dest_len + ft_strlen(src_swap));
	while (*src_swap)
	{
		if (size_swap != 1)
		{
			*dest_swap++ = *src_swap;
			size_swap--;
		}
		src_swap++;
	}
	*dest_swap = '\0';
	return (dest_len + (src_swap - src));
}
