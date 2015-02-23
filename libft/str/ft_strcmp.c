/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:09:46 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 23:28:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strcmp()  function compares the two strings s1 and s2.  It returns
** an integer less than, equal to, or greater than zero if  s1  is  found,
** respectively, to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
