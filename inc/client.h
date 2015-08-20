/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 21:14:04 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/19 15:23:41 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H

/*
** define
*/
# define CLIENT_H

/*
** include
*/
# include "ft_p.h"
# include <netinet/in.h>
# include <arpa/inet.h>

/*
** client prototypes
*/
void		c_read_stdin(int sock);
void		c_read_server(int sock);
void		c_sig_init(void);
void		client(char **av);

#endif //CLIENT_H
