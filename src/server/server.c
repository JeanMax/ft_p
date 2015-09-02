/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:34:22 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/27 10:55:10 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** server side
*/

#include "server.h"

int				g_cs[MAX_CLIENTS];
int				g_nb;

static int		create_server(int port)
{
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
}

void			accept_sock(int sock, t_env *e)
{
	socklen_t			cslen;
	struct sockaddr_in	csin;
	pid_t				pid;

	cslen = sizeof(csin);
	while (1)
	{
		g_nb++;
		if (!g_nb)
		{
			ft_putstr_clr("$Server> ", "g");
			ft_putendl("Waiting for connexion...");
		}
		if ((g_cs[g_nb] = accept(sock, (struct sockaddr *)&csin, &cslen)) == -1)
			error(ACCEPT, ft_itoa(sock));
		if ((pid = fork()) < 0)
			error(FORK, ft_itoa((int)pid));
		else if (pid)
			s_read_client(e);
	}
}

void			server(char **av, t_env *e)
{
	int				port;
	int				sock;

	g_nb = -1;
	ft_bzero((void *)g_cs, MAX_CLIENTS);
	port = ft_atoi(av[1]);
	s_sig_init();
	sock = create_server(port);
	accept_sock(sock, e);
	close(sock);
}
