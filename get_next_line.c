/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/21 09:46:07 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	t_dfile	*creat_dfile(int fd, t_dfile *next_fd)
{
	t_dfile	*elem;

dprintf(1, "			creat_elem====>fd:%d\n", fd);
	elem = (t_dfile*)malloc(sizeof(t_dfile));
	if (!elem)
		return (NULL);
	elem->next_fd = next_fd;
	elem->next_str = NULL;
	elem->i = 0;
	elem->str = (char*)malloc(sizeof(BUFF_SIZE + 1));
	if (!elem->str)
		return (NULL);
	if ((elem->size = read(fd, elem->str, BUFF_SIZE)) < 0)
		return (NULL);
//	else if (elem->size != BUFF_SIZE)
//		elem->size += read(fd, elem->str + elem->size, BUFF_SIZE - elem->size);
	*(elem->str + elem->size) = '\0';
	return (elem);
}

static	int		manip_branche(int mode, t_dfile *elem
				, t_dfile *prev, char *copy)
{
	t_dfile	*tmp;
	char	*str_buff;
	int		ret;

	ret = 1;
dprintf(1, "\n\n\n		:::: BEGIN MANIP_BRANCH ::::	mode:");
if (mode == COPY)
	dprintf(1, "[---COPY----]\n");
if (mode == CLEAN)
	dprintf(1, "[---CLEAN---]\n");
if (mode == DESTROY)
	dprintf(1, "[--DESTROY--]\n");

	if (mode == DESTROY && prev)
		prev->next_fd = elem->next_fd;
dprintf(1, "elem:%ld\n", (long)(elem));
if (mode == CLEAN)
	dprintf(1, "next:#%ld#\n", (long)(elem->next_str));
	while (elem && ((mode != CLEAN) || (elem->next_str)))
	{
dprintf(1, "bcl:%ld\n", (long)(elem));
		tmp = elem->next_fd;
		str_buff = elem->str;
		while (mode == COPY && *(str_buff) && *(str_buff) != TARGET_CHAR)
{
dprintf(1, "\nadr%ld	", (long)elem->str);
dprintf(1, "|%c", *str_buff);
			*(copy) = *(str_buff);
dprintf(1, "-%c", *(copy ));
			str_buff++;
			copy++;
}
	if (*(str_buff) == '\0')
{
	dprintf(1, "%cTHIS IS THE END\n", *(str_buff));
		ret = 0;
}
		if ((elem->next_str && mode == CLEAN) || mode == DESTROY)
		{
dprintf(1, "Holo hala yolo\n");
			tmp = elem->next_str;
dprintf(1, "Holo hala yolo2\nstr:%s\nadr:%ld\n", elem->str, (long)elem->str);
			if (elem->str && (*(elem->str)))
			{
dprintf(1, "kkkglojp::	|%s|\n", elem->str);
				free(elem->str);
			}
dprintf(1, "Holo hala yolo3\n");
			free(elem);
dprintf(1, "Holo hala yolo4\n");
		}
		else if (mode == COPY || mode == CLEAN)
			tmp = elem->next_str;
		elem = tmp;
	}
	if (mode == CLEAN && prev)
		prev->next_fd = elem;

dprintf(1, "		:::: ENDING MANIP_BRANCH ::::\n\n\n\n");
	return (ret);
}

static	t_dfile	*get_right_fd(t_dfile **lst, int fd, t_dfile **prev)
{
	t_dfile	*elem;

	elem = *lst;
	while (elem && elem->fd != fd)
	{
		*prev = elem;
		elem = elem->next_fd;
	}
	if (!elem)
	{
		elem = creat_dfile(fd, *lst);
		if (!elem)
			return (NULL);
		*lst = elem;
	}
	return (elem);
}

static	int		get_line(t_dfile *elem, t_dfile *prev, char **line, int fd)
{
	char	*str;
	int		nb_char;
	int		ret;

dprintf(1, "get_line\n");
	nb_char = 0;
	str = elem->str + elem->i;
	while (*str && *str != TARGET_CHAR)
	{
		while (*str && *str != TARGET_CHAR)
		{
dprintf(1, "str:%c\n", *(str));
			str++;
		}
dprintf(1, "this is the END1\n");
		nb_char += str - (elem->str - elem->i);
dprintf(1, "this is the END2\n");
dprintf(1, "str:%ld size:%d buff:%d\n", (long)(*str), elem->size, BUFF_SIZE);
		if (!(*(str))  && elem->size == (BUFF_SIZE))
		{
dprintf(1, "this is the END3\n");
			if (!(elem->next_str = creat_dfile(elem->fd, elem->next_fd)))
{
dprintf(1, "elem->next_str:%ld\n", (long)(elem->next_str));
dprintf(1, "memory elem error\n");
				return (-1);
}
			str = elem->str + elem->i;
		}
		else
{
	dprintf(1, "BOUH\n");
}
	}
	dprintf(1, "nb_char:%d\n", nb_char);
dprintf(1, "line:%ld\n", (long)(line));
dprintf(1, "*line:%ld\n", (long)(*line));
*line = (char*)malloc(sizeof(char) * (nb_char + 1));
	if (!line)
	{
dprintf(1, "trololole\n");
dprintf(1, "line:%ld\n", (long)(line));
dprintf(1, "memory line error for:%d\n", nb_char + 1);
		return (-1);
	}
	else
{
dprintf(1, "line:%ld\n", (long)(line));
dprintf(1, "*line:%ld\n", (long)(*line));
}
	ret = manip_branche(COPY, elem, prev, *line);
dprintf(1, "La c'est bon:::	|%s|\n", *line);
dprintf(1, "prev:%ld\n", (long)(prev));
	if (elem->size == BUFF_SIZE || ret)
		manip_branche(CLEAN, elem, prev, 0);
	else
{
		manip_branche(DESTROY, elem, prev, 0);
	dprintf(1, "copy:|%s|\n", *line);
		return (0);
}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	t_dfile	*lst = 0;
	t_dfile			*elem;
	t_dfile			*prev;
	int				error;

	prev = NULL;
	elem = get_right_fd(&lst, fd, &prev);
	if ((error = get_line(elem, prev, line, fd)) != 1)
	{
		return (error);
	}
	return (1);
}
