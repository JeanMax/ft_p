/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:34:22 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 07:09:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** server side
*/

#include "header.h"

int			g_cs[MAX_CLIENTS];
int			g_nb;

static int				create_server(int port)
{
	//DEBUG; //debug
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
		error(PROTO, "tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
		error(BIND, ft_itoa(port));
	listen(sock, MAX_CLIENTS);
	return (sock);
	//DEBUG; //debug
}

static void			recurs_accept(int sock, pid_t stdin_reader_pid, t_env *e)
{
	//DEBUG; //debug
//	ft_debugnbr("killed", stdin_reader_pid); //debug
	if (kill(stdin_reader_pid, SIGTERM))
		if (kill(stdin_reader_pid, SIGKILL))
			error(KILL, ft_itoa((int)stdin_reader_pid));
	if ((stdin_reader_pid = fork()) < 0)
		error(FORK, ft_itoa((int)stdin_reader_pid));
	else if (stdin_reader_pid) //father
		accept_sock(sock, stdin_reader_pid, e);
	else //son
		s_read_stdin();
	//DEBUG; //debug
}

void			accept_sock(int sock, pid_t stdin_reader_pid, t_env *e)
{
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				pid;

	//DEBUG; //debug
	g_nb++;
//	ft_debugnbr("tokill", stdin_reader_pid); //debug
	if (!g_nb)
		ft_putstr_clr("$Server> ", "g"), ft_putendl("Waiting for connexion...");
	if ((g_cs[g_nb] = accept(sock, (struct sockaddr *)&csin, &cslen)) == -1)
		error(ACCEPT, ft_itoa(sock));
	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		recurs_accept(sock, stdin_reader_pid, e);
	else //son
		s_read_client(e);
	//DEBUG; //debug
}

void				server(char **av, t_env *e)
{
	int				port;
	int				sock;
	pid_t			pid;

	//DEBUG; //debug
	g_nb = -1;
	ft_bzero((void *)g_cs, MAX_CLIENTS);
	port = ft_atoi(av[1]);
	s_sig_init();
	sock = create_server(port);
	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		accept_sock(sock, pid, e);
	else //son
		s_read_stdin();
	close(sock);
	//DEBUG; //debug
}
