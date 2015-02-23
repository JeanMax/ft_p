/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:54:09 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/14 20:16:02 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print an integer on stdout.
*/

#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483647 - 1)
		ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar('0' + nbr);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}
