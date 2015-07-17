/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 04:11:05 by mcanal            #+#    #+#             */
/*   Updated: 2015/03/09 01:45:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks  for  any  printable character which is not a space or an
** alphanumeric character.
*/

#include "libft.h"

int ft_ispunct(int c)
{
	if (c != ' ' && !ft_isalnum(c) && ft_isprint(c))
		return (8);
	return (0);
}
