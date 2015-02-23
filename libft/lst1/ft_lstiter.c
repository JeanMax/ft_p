/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:29:26 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/12 14:56:49 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f.
*/

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst && f)
	{
		if (lst->next != NULL)
		{
			f(lst);
			ft_lstiter(lst->next, f);
		}
		else
			f(lst);
	}
}
