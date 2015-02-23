/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:34:22 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 00:40:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** server side
*/

#include "header.h"

static int				create_server(int port)
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
		error(BIND, NULL);
	listen(sock, 42);
	return (sock);
}

static void		 accept_sock(int sock)
{
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	char				*all;

	if ((cs = accept(sock, (struct sockaddr *)&csin, &cslen)) == -1)
		error(ACCEPT, ft_itoa(sock));
	while (get_line(cs, &all))
		ft_debugstr("Received", all);
	close(cs);
}

void				server(char **av)
{
	int				port;
	int				sock;

	port = ft_atoi(av[1]);
	sock = create_server(port);
	accept_sock(sock);
	close(sock);
}
