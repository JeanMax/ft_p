/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:24:49 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/27 01:35:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allows to print an int variable preceded by its name (debug!)
*/

#include "libft.h"

void	ft_debugnbr(char *name, int nbr)
{
	ft_putchar_clr('<', "r");
	ft_putstr_clr(name, "r");
	ft_putstr_clr(":", "r");
	ft_putnbr_clr(nbr, "g");
	ft_putendl_clr(">", "r");
}
