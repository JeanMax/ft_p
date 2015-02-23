/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:44:12 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:34:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks for any printable character including space.
*/

#include "libft.h"

int		ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
