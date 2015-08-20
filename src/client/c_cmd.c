/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 20:44:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/20 16:58:44 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** local commands for client
*/

#include "client.h"

void	exec_local(char *cmd, t_env *e)
{
	char	*tmp;
	pid_t	pid;
    char	**cmd_tab;

    if (!(cmd_tab = split_that(cmd, e)))//TODO: Free
        return ; //...
    check_cmd(cmd_tab, e);
	tmp = ft_strjoin("/bin/", cmd_tab[0]);
	if ((pid = (int)fork()) < 0)
		error(FORK, ft_itoa(pid));
	else if (!pid)
		execv(tmp, cmd_tab), error(EXECV, tmp), exit(-1);
	else
		wait(NULL);
    //TODO: success/error
	ft_memdel((void *)&tmp);
}
