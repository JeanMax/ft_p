/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 23:23:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define TRUE 1
# define FALSE 0
# define MALLOC 1
# define USAGE 2
# define USAGE_MSG " <port>"

/*
** include
*/
# include "../libft/inc/libft.h"
# include <stdlib.h>

/*
** struct && typedef
*/
typedef struct s_env	t_env;
struct		s_env
{
	t_char todo;
};

/*
** prototypes
*/
void		error(char error, char *msg);

#endif
