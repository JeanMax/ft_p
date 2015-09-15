/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whoami.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 23:40:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/15 19:09:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern int	g_nb;

void		whoami(int c_fd)
{
	char	*tmp;

	tmp = ft_itoa(g_nb);
	send_str("You are the client number ", c_fd);
	send_str(tmp, c_fd);
	send_str(".\nSUCCESS\n", c_fd);
	ft_memdel((void *)&tmp);
}
