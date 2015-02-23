/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lisn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 23:47:29 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/22 14:26:02 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne la position de l'élément dans la liste (premier = 1)
** 0 est retourné en cas d'echec
*/

#include "libft.h"

int ft_lisn(t_lst **alst, t_lst *lst)
{
	t_lst	*tmp;
	size_t	i;

	if (!alst || !lst)
		return (0);
	if (*alst == lst)
		return (1);
	tmp = *alst;
	i = 2;
	while (tmp->next != NULL && tmp->next != lst)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->next != lst)
		return (0);
	return (i);
}
