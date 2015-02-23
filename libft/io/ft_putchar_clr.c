/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:53:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/09 03:35:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print the char c on stdout, with colors!
** clr = yellow, blue, red, green, pink, sky, white, (default = grey)
*/

#include "libft.h"
#include <unistd.h>

void	ft_putchar_clr(char c, char *clr)
{
	char str[13];

	ft_strcpy(str, "\033[30;01mX\033[0m");
	str[8] = c;
	str[3] = (clr[0] == 'r' ? '1' : str[3]);
	str[3] = (clr[0] == 'g' ? '2' : str[3]);
	str[3] = (clr[0] == 'y' ? '3' : str[3]);
	str[3] = (clr[0] == 'b' ? '4' : str[3]);
	str[3] = (clr[0] == 'p' ? '5' : str[3]);
	str[3] = (clr[0] == 's' ? '6' : str[3]);
	str[3] = (clr[0] == 'w' ? '7' : str[3]);
	write(1, str, 13);
}
