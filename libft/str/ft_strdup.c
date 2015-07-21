/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:11:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 19:14:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function returns a pointer to a  new  string  which  is  a
** duplicate  of the string s.  Memory for the new string is obtained with
** malloc(3), and can be freed with free(3).
*/

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(char *src)
{
	char			*dup;
	char			*swap;

	if (!src)
		return (NULL);
	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	swap = dup;
	while (*src)
		*(dup++) = *(src++);
	*dup = 0;
	return (swap);
}
