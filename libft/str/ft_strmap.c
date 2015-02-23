/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:38:29 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:18:54 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Apply the function f to every character of the character string
** given in parameter to create a new fresh string (with malloc (3))
** resulting from successive applications of f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (0);
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
