/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 20:44:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/15 22:06:20 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** local commands for client
*/

#include "client.h"

char			exec_local(char *cmd, t_env *e)
{
	char	*tmp;
	pid_t	pid;
	char	**cmd_tab;
	int		status;

	status = 42;
	!(cmd_tab = split_that(cmd)) ? error(MALLOC, "cmd_tab") : (void)0;
	check_cmd(cmd_tab, e);
	if (*(cmd + 1) == 'c' && *(cmd + 2) == 'd')
		return (c_cd(cmd_tab, e));
	tmp = ft_strjoin("/bin/", *cmd_tab + 1);
	if ((pid = (int)fork()) < 0)
		error(FORK, ft_itoa(pid));
	else if (!pid)
	{
		execv(tmp, cmd_tab);
		error(EXECV, tmp);
	}
	else
		wait4(pid, &status, 0, NULL);
	ft_memdel((void *)&tmp);
	ft_freestab(cmd_tab);
	return (WEXITSTATUS(status) ? FALSE : TRUE);
}
