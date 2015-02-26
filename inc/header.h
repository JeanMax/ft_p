/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/26 20:24:55 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define TRUE 1
# define FALSE 0
# define MAX_CLIENTS 1024
# define S_USAGE_MSG " <port>"
# define C_USAGE_MSG " <adrr> <port>"
# define S_USAGE 0
# define C_USAGE 1
# define MALLOC 2
# define PROTO 3
# define BIND 4
# define ACCEPT 5
# define CONNECT 6
# define FORK 7
# define BUS 8
# define SEG 9
# define FPE 10
# define KILL 11
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug


/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/wait.h>
# include <signal.h>

/*
** struct && typedef
*/
typedef struct s_env	t_env;
struct		s_env
{
	t_char todo;
};

/*
** prototypes
*/
void		error(char error, char *msg);

void		client(char **av);

void		accept_sock(int sock, pid_t stdin_reader_pid);
void		server(char **av);

#endif
