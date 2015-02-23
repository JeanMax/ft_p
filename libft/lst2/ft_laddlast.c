/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_laddlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 03:07:11 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/22 14:22:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ajoute l’élément new en fin de la liste. **alst pointe vers un élément
** quelconque de la liste. La fonction assume que la liste possède au moins
** un élément.
*/

#include "libft.h"

void ft_laddlast(t_lst **alst, t_lst *new)
{
	t_lst	*tmp;

	if (!alst || !new)
		return ;
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
