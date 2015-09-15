/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 23:09:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/15 21:42:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_char		is_cmd(char *line)
{
	if (ft_strncmp(line, "ls ", 3) && ft_strcmp(line, "pwd") && \
		ft_strncmp(line, "cat ", 4) && ft_strncmp(line, "chmod ", 6) && \
		ft_strncmp(line, "cp ", 3) && ft_strncmp(line, "mkdir ", 6) && \
		ft_strncmp(line, "mv ", 3) && ft_strncmp(line, "rm ", 3) && \
		ft_strncmp(line, "get ", 4) && ft_strncmp(line, "put ", 4) && \
		ft_strncmp(line, "cd ", 3) && ft_strcmp(line, "whoami") && \
		ft_strcmp(line, "ls") && ft_strcmp(line, "cd") \
		&& ft_strcmp(line, "help"))
		return (FALSE);
	return (TRUE);
}

t_char		is_local_cmd(char *line)
{
	if (ft_strncmp(line, "lls ", 4) && ft_strcmp(line, "lpwd") && \
		ft_strncmp(line, "lcat ", 5) && ft_strncmp(line, "lchmod ", 7) && \
		ft_strncmp(line, "lcp ", 4) && ft_strncmp(line, "lmkdir ", 7) && \
		ft_strncmp(line, "lmv ", 4) && ft_strncmp(line, "lrm ", 4) && \
		ft_strncmp(line, "lcd ", 4) && \
		ft_strcmp(line, "lls") && ft_strcmp(line, "lcd"))
		return (FALSE);
	return (TRUE);
}
