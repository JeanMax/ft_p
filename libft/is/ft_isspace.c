/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 04:11:38 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/10 17:26:16 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks for white-space  characters.   In  the  "C"  and  "POSIX"
** locales,  these  are:  space,  form-feed ('\f'), newline ('\n'),
** carriage return ('\r'), horizontal tab ('\t'), and vertical  tab
** ('\v').
*/

#include "libft.h"

int ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}
