/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:29:26 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/22 14:41:39 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f.
*/

#include "libft.h"

void ft_liter(t_lst *lst, void (*f)(t_lst *elem))
{
	if (lst && f)
	{
		if (lst->next != NULL)
		{
			f(lst);
			ft_liter(lst->next, f);
		}
		else
			f(lst);
	}
}
