/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:58:41 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/16 03:13:31 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Free a char * tab
*/

#include "libft.h"

void	ft_freestab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_memdel((void *)&tab[i++]);
	ft_memdel((void *)&tab);
}
