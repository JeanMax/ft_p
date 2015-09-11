/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:44:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 19:24:44 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strncmp() function  is similar to strcmp(), except it compares the
** only first (at most) n bytes of s1 and s2.
*/

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (FALSE);
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (n ? (unsigned char)*s1 - (unsigned char)*s2 : \
				(unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
}
