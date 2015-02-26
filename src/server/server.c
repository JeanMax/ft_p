/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:34:22 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/26 22:47:58 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** server side
*/

#include "header.h"

int			g_cs[MAX_CLIENTS];
int			g_nb;

static void	sig_handl(int sig)
{
	if (sig == SIGBUS)
		error(BUS, NULL);
	else if (sig == SIGSEGV)
		error(SEG, NULL);
	else if (sig == SIGFPE)
		error (FPE, NULL);
	else if (sig == SIGINT)
	{
		ft_putstr("\b \b\b \bquit");
		sig = 0;
		while (sig <= g_nb)
			g_cs[sig] > 0 ? ft_putendl_fd("quit", g_cs[sig]) : NULL, sig++;
		exit(0);
	}
	else if (sig == 29)
		ft_putstr_clr("$Server> ", "g");
}

static int				create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
		error(BIND, ft_itoa(port));
	listen(sock, MAX_CLIENTS);
	return (sock);
}

static void			read_stdin(void)
{
	int		i;
	char	*line;

	signal(SIGINT, sig_handl);
	while (get_line(0, &line))
	{
		ft_putstr_clr("$Server> ", "g");
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (ft_strlen(line) > 0)
		{
			i = 0;
			while (i <= g_nb)
				ft_putendl_fd(line, g_cs[i++]);
		}
		ft_memdel((void *)&line);
	}
	i = 0;
	while (i <= g_nb)
		ft_putendl_fd("quit", g_cs[i++]);
	ft_putendl("All clients disconnected.");
	ft_putstr_clr("$Server> ", "g");
}

static void			read_client(void)
{
	char		*line;

	!g_nb ? ft_putstr_clr("$Server> ", "g"): NULL;
	ft_putstr("Hey "), ft_putnbr(g_nb);
	ft_putstr_clr("\n$Server> ", "g");
	while (get_line(g_cs[g_nb], &line))
	{
		if (!ft_strcmp(line, "quit"))
			break ;
		else if (!ft_strcmp(line, "whoami"))
		{
			ft_putstr_fd("You are the client number ", g_cs[g_nb]);
			ft_putnbr_fd(g_nb, g_cs[g_nb]);
			ft_putendl_fd(".", g_cs[g_nb]);
		}
		else if (ft_strlen(line) > 0)
		{
			ft_putstr("Client "), ft_putnbr(g_nb), ft_putstr(": ");
			ft_putendl(line);
			ft_putstr_clr("$Server> ", "g");
		}
		ft_memdel((void *)&line);
	}
	ft_putendl_fd("quit", g_cs[g_nb]);
	ft_putstr("Bye "), ft_putnbr(g_nb), ft_putstr_clr("\n$Server> ", "g");
}

static void			recurs_accept(int sock, pid_t stdin_reader_pid)
{
	pid_t			pid;

	if (kill(stdin_reader_pid, SIGTERM))
		if (kill(stdin_reader_pid, SIGKILL))
			error(KILL, ft_itoa((int)stdin_reader_pid));
	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		accept_sock(sock, pid);
	else //son
		read_stdin();
}

static void			fork_it(int sock, pid_t stdin_reader_pid)
{
	pid_t		pid;

	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		recurs_accept(sock, stdin_reader_pid);
	else //son
		read_client();
}

void		accept_sock(int sock, pid_t stdin_reader_pid)
{
	unsigned int		cslen;
	struct sockaddr_in	csin;

	g_nb++;
	if (!g_nb)
		ft_putstr_clr("$Server> ", "g"), ft_putendl("Waiting for connexion...");
	if ((g_cs[g_nb] = accept(sock, (struct sockaddr *)&csin, &cslen)) == -1)
		error(ACCEPT, ft_itoa(sock));
	else
		fork_it(sock, stdin_reader_pid);
}

void				server(char **av)
{
	int				port;
	int				sock;
	pid_t			pid;

	g_nb = -1;
	ft_bzero((void *)g_cs, MAX_CLIENTS);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	if ((pid = fork()) < 0)
		error(FORK, ft_itoa((int)pid));
	else if (pid) //father
		accept_sock(sock, pid);
	else //son
		read_stdin();
	close(sock);
}
