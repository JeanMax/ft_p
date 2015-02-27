/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 10:14:16 by mcanal           ###   ########.fr       */
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
# define PATH_SIZE 256
# define S_USAGE_MSG " <port> [minimum folder]"
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
# define EXECV 12
# define ENV 13
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
	char	*old_pwd;
	char	*pwd;
	char	*home;
	char	*stop;
	char	**ae;
};

/*
** common prototypes
*/
void		error(char error, char *msg);

/*
** client prototypes
*/
void		c_read_stdin(int sock);
void		c_read_server(int sock);
void		c_sig_init(void);
void		client(char **av);

/*
** server prototypes
*/
char		*get_env(char *var, t_env *e);
char		ft_cd(char **av, t_env *e, int fd);
void		exec_cmd(char *cmd, t_env *e);
void		s_read_stdin(void);
void		s_read_client(t_env *e);
void		s_sig_init(void);
void		s_sig_handl(int sig);
void		accept_sock(int sock, pid_t stdin_reader_pid, t_env *e);
void		server(char **av, t_env *e);

#endif
