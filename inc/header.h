/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 13:44:55 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define MAX_CLIENTS	1024
# define PATH_SIZE		256
# define S_USAGE_MSG	" <port> [minimum folder]"
# define C_USAGE_MSG	" <adrr> <port>"

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
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <fcntl.h>

/*
** enum
*/
enum	e_error
{
	S_USAGE,
	C_USAGE,
	MALLOC,
	PROTO,
	BIND,
	ACCEPT,
	CONNECT,
	FORK,
	BUS,
	SEG,
	FPE,
	KILL,
	EXECV,
	ENV,
	OPEN,
	PATH
};

/*
** struct && typedef
*/
typedef struct s_env	t_env;
struct		s_env
{
	char	*old_pwd;
	char	*pwd;
	char	*home;
	char	*path;
	char	**ae;
};

/*
** common prototypes
*/
void		error(char error, char *msg);
t_char		is_cmd(char *line);
t_char		send_str(char const *str, int fd);
t_char		send_endl(char const *str, int fd);
size_t		recv_msg(int const fd, char **line);
t_char		send_file(char *file, int fd);
t_char		recv_file(char *file, int fd);

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
void		fill_env(char **ae, t_env *e, char *stop);
char		*get_env(char *var, t_env *e);
char		ft_cd(char **av, t_env *e, int fd);
void		whoami(int c_fd);
char		**permission_granted(char *cmd, t_env *e);
void		exec_cmd(char *cmd, t_env *e, int c_fd);
void		s_read_client(t_env *e);
void		s_sig_init(void);
void		s_sig_handl(int sig);
void		accept_sock(int sock, t_env *e);
void		server(char **av, t_env *e);

#endif
