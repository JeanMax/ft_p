/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 23:09:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/21 01:15:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_char		is_cmd(char *line)
{
	if (ft_strncmp(line, "ls", 2) && ft_strcmp(line, "pwd") && \
		ft_strncmp(line, "cat", 3) && ft_strncmp(line, "chmod", 5) && \
		ft_strncmp(line, "cp", 2) && ft_strncmp(line, "mkdir", 5) && \
		ft_strncmp(line, "mv", 2) && ft_strncmp(line, "rm", 2) && \
		ft_strncmp(line, "sleep", 5) && ft_strncmp(line, "get", 3) && \
		ft_strncmp(line, "put", 3) && \
		ft_strncmp(line, "cd", 2) && ft_strcmp(line, "whoami"))
		return (0);
	return (1);
}
