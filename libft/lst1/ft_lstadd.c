/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:27:33 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/12 14:38:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ajoute l’élément new en tête de la liste.
*/

#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
}
