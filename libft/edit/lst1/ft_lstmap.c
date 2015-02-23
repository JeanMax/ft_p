/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:31:48 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/11 16:25:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f
** et crée une nouvelle liste “fraiche” avec malloc(3) résultant des
** applications successives. Si une allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alist;
	t_list	*new_list;
	t_list	*link;

	if (!lst || !f)
		return (0);
	link = f(lst);
	new_list = ft_lstnew(link->content, link->content_size);
	if (!new_list)
		return (0);
	alist = new_list;
	while (lst->next != NULL)
	{
		link = f(lst->next);
		new_list->next = ft_lstnew(link->content, link->content_size);
		if (new_list->next == NULL)
			return (0);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (alist);
}
