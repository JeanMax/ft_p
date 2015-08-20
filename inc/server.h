/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 21:17:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/19 15:23:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H

/*
** define
*/
# define SERVER_H

/*
** include
*/
# include "ft_p.h"
# include <sys/wait.h>

/*
** server prototypes
*/
void		fill_env(char **ae, t_env *e, char *stop); //TODO: move to shared
char		*get_env(char *var, t_env *e); //TODO: move to shared
char		ft_cd(char **av, t_env *e, int fd); //TODO: make compatible to client
void		whoami(int c_fd);
char		**permission_granted(char *cmd, t_env *e); //TODO: extract split
void		exec_cmd(char *cmd, t_env *e, int c_fd);
void		s_read_client(t_env *e);
void		s_sig_init(void);
void		s_sig_handl(int sig);
void		accept_sock(int sock, t_env *e);
void		server(char **av, t_env *e);

#endif //SERVER_H
