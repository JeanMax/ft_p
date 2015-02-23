/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:25:32 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/25 17:40:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne la taille de la liste
*/

#include "libft.h"

int	ft_llen(t_lst **alst)
{
	t_lst	*tmp;
	size_t	i;

	if (!alst)
		return (0);
	tmp = *alst;
	i = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
