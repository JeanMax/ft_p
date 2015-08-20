/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/20 16:43:14 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H

/*
** define
*/
# define FT_P_H
# define MAX_CLIENTS	1024
# define PATH_SIZE		256
# define S_USAGE_MSG	" <port> [minimum folder]"
# define C_USAGE_MSG	" <adrr> <port>"

/*
** include
*/
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <netdb.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

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
t_char		is_local_cmd(char *line);
t_char		send_str(char const *str, int fd);
size_t		recv_msg(int const fd, char **line);
t_char		send_file(char *file, int fd);
t_char		recv_file(char *file, int fd);
void		fill_env(char **ae, t_env *e, char *stop);
char		*get_env(char *var, t_env *e);
char		**split_that(char *s, t_env *e);
void		check_cmd(char **cmd, t_env *e);

#endif
