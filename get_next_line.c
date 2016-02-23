/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/23 13:55:34 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static	int		get_line(t_dfile *elem, t_dfile *prev, char **line, int *error)
{

}

int	get_next_line(int const fd, char **line)
{
	static	t_dfile	*lst = 0;
	t_dfile			*elem;
	t_dfile			*prev;
	int				error;

	prev = NULL;
	elem = get_right_fd(&lst, fd, &prev);
	if ((get_line(elem, prev, line, &error) != 1))
		return (error);
	return (1);
}

