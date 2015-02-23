/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:19:06 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/09 03:31:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print the char * s on stdout, with colors!
** clr = yellow, blue, red, green, pink, sky, white, (default = grey)
*/

#include "libft.h"

void	ft_putstr_clr(char const *s, char *clr)
{
	while (*s)
		ft_putchar_clr(*s++, clr);
}
