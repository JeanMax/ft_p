/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:44:15 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 23:04:39 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assign (with malloc (3)) and returns a  fresh character string
** ended with one '\0' resulting from the concatenation of s1 and s2.
** If the allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
