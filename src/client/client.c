/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:34:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/27 06:37:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** client side
*/

#include "header.h"

static int				create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
		error(PROTO, "tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
		error(CONNECT, addr);
	return (sock);
}

void					client(char **av)
{
	int				port; //del var?
	int				sock;
	pid_t			pid;

	port = ft_atoi(av[2]);
	c_sig_init();
	sock = create_client(av[1], port);
	ft_putstr_clr("$Client> ", "g");
	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		c_read_server(sock);
	else //son
		c_read_stdin(sock);
}