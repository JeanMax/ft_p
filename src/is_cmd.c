/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 23:09:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/24 16:48:55 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_char		is_cmd(char *line)
{
	if (ft_strncmp(line, "ls ", 3) && ft_strcmp(line, "pwd") && \
		ft_strncmp(line, "cat ", 4) && ft_strncmp(line, "chmod ", 6) && \
		ft_strncmp(line, "cp ", 3) && ft_strncmp(line, "mkdir ", 6) && \
		ft_strncmp(line, "mv ", 4) && ft_strncmp(line, "rm ", 3) && \
		ft_strncmp(line, "get ", 4) && ft_strncmp(line, "put ", 4) && \
		ft_strncmp(line, "cd ", 3) && ft_strcmp(line, "whoami") && \
		ft_strcmp(line, "ls") && ft_strcmp(line, "cd") \
		&& ft_strcmp(line, "help"))
		return (0);
	return (1);
}
