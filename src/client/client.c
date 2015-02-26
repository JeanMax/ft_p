/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:34:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/26 22:27:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** client side
*/

#include "header.h"

static void	 sig_handl(int sig)
{
	if (sig == SIGBUS)
		error(BUS, NULL);
	else if (sig == SIGSEGV)
		error(SEG, NULL);
	else if (sig == SIGFPE)
		error (FPE, NULL);
	else if (sig == SIGINT)
	{
		ft_putstr("\b \b\b \b\n");
		ft_putstr_clr("$Client> ", "g");
	}
	else if (sig == 29)
		ft_putstr_clr("$Client> ", "g");
}

static int				create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	signal(SIGINT, sig_handl);
	signal(SIGFPE, sig_handl);
	signal(29, sig_handl);
	signal(SIGSEGV, sig_handl);
	signal(SIGBUS, sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
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

static void				read_stdin(char *line, int sock)
{
	signal(SIGINT, SIG_IGN);
	while (get_line(0, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		ft_putstr_clr("$Client> ", "g");
		ft_putendl_fd(line, sock);
		ft_memdel((void *)&line);
	}
	ft_putendl_fd("quit", sock);
	close(sock), exit(0);
}

static void				read_server(char *line, int sock)
{
	while (get_line(sock, &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		ft_putstr("Server: "), ft_putendl(line);
		ft_putstr_clr("$Client> ", "g");
		ft_memdel((void *)&line);
	}
	ft_putendl("Connexion to server closed."), close(sock), exit(0);
}

void					client(char **av)
{
	int				port; //del var?
	int				sock;
	pid_t			pid;
	char			*line;

	line = NULL;
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putstr_clr("$Client> ", "g");
	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		read_server(line, sock);
	else //son
		read_stdin(line, sock);
}
