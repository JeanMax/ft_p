/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 23:42:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/20 23:42:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*get_env(char *var, t_env *e)
{
	char		**ae;
	int			 i;
	size_t		 len;

	ae = e->ae;
	i = 0;
	len = ft_strlen(var);
	while (ae[i] && ft_strncmp(ae[i], var,
						   (int)ft_strlen(var) > ft_strindex(ae[i], '=') ?
						   ft_strlen(var) : (size_t)ft_strindex(ae[i], '=')))
		i++;
	return (ae[i] ? ft_strdup(ae[i] + len + 1) : ft_strnew(1));
}
