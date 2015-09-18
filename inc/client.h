/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 21:14:04 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/18 19:55:10 by mcanal           ###   ########.fr       */
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
char		exec_local(char *cmd, t_env *e);
char		c_cd(char **av, t_env *e);
void		c_read_stdin(int sock);
void		c_read_server(int sock, t_env *e);
void		c_sig_init(void);
void		client(char **av, t_env *e);

#endif
