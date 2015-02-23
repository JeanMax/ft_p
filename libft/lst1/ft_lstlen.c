/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 04:25:32 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/12 18:42:34 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne la taille de liste
*/

#include "libft.h"

int	ft_lstlen(t_list **alst)
{
	t_list	*tmp;
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
