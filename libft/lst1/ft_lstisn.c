/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 23:47:29 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/12 08:53:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne la position de l'élément dans la liste (premier = 1)
** 0 est retourné en cas d'echec
*/

#include "libft.h"

int ft_lstisn(t_list **alst, t_list *lst)
{
	t_list	*tmp;
	int		i;

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
