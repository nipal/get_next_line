/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:53:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/22 11:11:29 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	print_dfile(t_dfile *elem)
{
	int	i;

	i = 0;
	if (elem)
	{
		if (DEBUG && PRINT_VALID)
			dprintf(1, "ok\n");
		if (DEBUG && PRINT_NEXT_STR)
			dprintf(1, "next_fd:%ld\n", (long)elem->next_fd);	
		if (DEBUG && PRINT_NEXT_FD)
			dprintf(1, "next_str:%ld\n", (long)elem->next_str);	
		if (DEBUG && PRINT_FD)
			dprintf(1, "fd:%d\n", elem->fd);	
		if (DEBUG && PRINT_I)
			dprintf(1, "i:%d\n", elem->i);	
		if (DEBUG && PRINT_SIZE)
			dprintf(1, "size:%d\n", elem->size);	

		if (DEBUG && PRINT_STR)
		{
			while (i < elem->i + 4)
			{
				write(1, " ", 1);
				i++;
			}
			write(1, "|\n", 2);
			dprintf(1, "str:|%s|\n", elem->str);	
			i = 0;
			while (i < elem->size + 5)
			{
				write(1, " ", 1);
				i++;
			}
			write(1, "#\n", 2);

		}
	}
	else
	{
		if (DEBUG && PRINT_VALID)
			dprintf(1, "null\n");
	}
	dprintf(1, "\n");
}

void print_str_branch(t_dfile *begin)
{
	t_dfile	*elem;

	elem = begin;
	while (elem)
	{
		print_dfile(elem);
		elem = elem->next_str;
	}
}

void print_all(t_dfile *begin)
{
	t_dfile	*elem;

	elem = begin;
	while (elem)
	{
		print_str_branch(elem);
		elem = elem->next_fd;
	}
}

static	t_dfile	*creat_dfile(int fd, t_dfile *next_fd)
{
	t_dfile	*elem;

	elem = NULL;
	if (DEBUG && DEBUG_CREAT_DFILE)
	{
		dprintf(1, "\n\n\n=======>CREAT_DFILE fd:%d    ::::\n", fd);
	}
	elem = (t_dfile*) malloc(sizeof(t_dfile));
	if (!elem)
	{
		if (DEBUG && DEBUG_CREAT_DFILE)
			dprintf(1, "n::::  END_CREAT_DFILE (null-elem)  ::::\n");
		return (NULL);
	}
	elem->next_fd = next_fd;
	elem->next_str = NULL;
	elem->i = 0;
	elem->fd = fd;
	elem->str = (char*)malloc(sizeof(BUFF_SIZE + 1));
	if (!elem->str)
	{
		if (DEBUG && DEBUG_CREAT_DFILE)
			dprintf(1, "::::  END_CREAT_DFILE (null-str)  ::::\n");
		return (NULL);
	}
	if ((elem->size = read(fd, elem->str, BUFF_SIZE)) < 0)
	{
		if (DEBUG && DEBUG_CREAT_DFILE)
			dprintf(1, "::::  END_CREAT_DFILE (err->read)  ::::\n");
		return (NULL);
	}
	*(elem->str + elem->size) = '\0';
	if (DEBUG && DEBUG_CREAT_DFILE && PRINT_ELEM)
		print_dfile(elem);
	if (DEBUG && DEBUG_CREAT_DFILE)
		dprintf(1, "::::  END_CREAT_DFILE  (ok)   ::::\n");
	return (elem);
}

static	int		manip_branche(int mode, t_dfile *elem, t_dfile *prev, char *copy)
{
	t_dfile	*tmp;
	char	*str_buff;
	int		ret;

char *save_copy = copy;

	ret = 1;

if (DEBUG_MANIP_BRANCH && DEBUG)
{
	dprintf(1, "\n\n\n:::: BEGIN MANIP_BRANCH	 ::::	mode:");
	if (mode == COPY)
		dprintf(1, "[---COPY----]\n");
	if (mode == CLEAN)
		dprintf(1, "[---CLEAN---]\n");
	if (mode == DESTROY)
		dprintf(1, "[--DESTROY--]\n");
}


	if (mode == COPY)
		print_str_branch(elem);
	if (mode == DESTROY && prev)
		prev->next_fd = elem->next_fd;
//	if (mode == CLEAN)
//	{
		while (elem && ((mode != CLEAN) || (elem->next_str)))
		{
			tmp = elem->next_fd;
			str_buff = elem->str + elem->i ;
			while (mode == COPY && *(str_buff) && *(str_buff) != TARGET_CHAR)
			{
				*(copy) = *(str_buff);
				str_buff++;
				copy++;
				elem->i++;
			}
				elem->i++;
			if (mode == COPY)
			{
				*(copy) = '\0';
			}
			if (*(str_buff) == '\0')
			{
				ret = 0;
			}
			if ((elem->next_str && mode == CLEAN) || mode == DESTROY)
			{
				tmp = elem->next_str;
				if (elem->str && (*(elem->str)))
				{
					free(elem->str);
				}
				free(elem);
			}
			else if (mode == COPY || mode == CLEAN)
				tmp = elem->next_str;
			elem = tmp;
		}
	if (mode == COPY && DEBUG && PRINT_COPY_SIZE)
		dprintf(1, "size_str:%ld\n", (long)(copy - save_copy));
//	}
	if (mode == CLEAN && prev)
		prev->next_fd = elem;

	if (DEBUG_MANIP_BRANCH && DEBUG)
	{
		dprintf(1, "---- ENDING MANIP_BRANCH ----\n\n\n\n");
	}
	return (ret);
}

static	t_dfile	*get_right_fd(t_dfile **lst, int fd, t_dfile **prev)
{
	t_dfile	*elem;

	if (DEBUG && DEBUG_GET_RIGHT_FD)
	{
		dprintf(1, "::::   GET_THE_RIGHT_FD  ::::\n");
	}

	elem = *lst;
	while (elem && elem->fd != fd)
	{
		if (DEBUG && DEBUG_GET_RIGHT_FD && PRINT_WRONG_FD)
			{dprintf(1, "			fd_wrong:%d\n", elem->fd);}
		*prev = elem;
		elem = elem->next_fd;
	}
	if (!elem)
	{
		if (DEBUG && DEBUG_GET_RIGHT_FD && PRINT_NEW_FD)
			{dprintf(1, "			fd_creat:%d\n", fd);}
		elem = creat_dfile(fd, *lst);
		if (!elem)
		{
			if (DEBUG && DEBUG_GET_RIGHT_FD)
				{dprintf(1, "----       END_GET_creat ----\n");}
			return (NULL);
		}
		*lst = elem;
	}

	if (DEBUG && DEBUG_GET_RIGHT_FD)
	{
		dprintf(1, "----       END_GET_find  ----\n");
	}
	return (elem);
}

static	int		get_line(t_dfile *begin, t_dfile *prev, char **line)
{
	char		*str;
	int			nb_char;
	int			ret;
	t_dfile	*elem;
	
	elem = begin;
	if (DEBUG && DEBUG_GET_LINE)
		dprintf(1, "::::       GET_LINE      ::::\n");
	nb_char = 0;
	str = elem->str + elem->i;
	
//	on cherche un '\n' si il n'y en a pas a la fin du buffeur on recupere une autre element
	while (*str && *str != TARGET_CHAR)
	{
		while (*str && *str != TARGET_CHAR)
			str++;
		nb_char += str - (elem->str - elem->i);
		if (!(*(str))  && elem->size == (BUFF_SIZE))
		{
			if (!(elem->next_str = creat_dfile(elem->fd, elem->next_fd)))
			{
				if (DEBUG && DEBUG_GET_LINE)
					dprintf(1, "::::     END_GET_LINE -1  ::::\n");
				return (-1);
			}
			elem = elem->next_str;
			str = elem->str + elem->i;
		}
	}

//	on connai la taille on malloc une chaine
*line = (char*)malloc(sizeof(char) * (nb_char + 1));
	if (!line)
	{
		if (DEBUG && DEBUG_GET_LINE)
			dprintf(1, "::::     END_GET_LINE -1  ::::\n");
		return (-1);
	}

// on copy la chaine si 
	ret = manip_branche(COPY, begin, prev, *line);

	if (DEBUG && DEBUG_GET_LINE && PRINT_RESULT)
		dprintf(1, "line:|%s|\n", *line);
// on clean si on a remplis le buffer ou sinon si le dernier \n n'est pas a la fin de la chaine 
	if (elem->size == BUFF_SIZE || ret)
		manip_branche(CLEAN, begin, prev, 0);
	else
	{
		manip_branche(DESTROY, begin, prev, 0);
		if (DEBUG && DEBUG_GET_LINE)
			dprintf(1, "::::     END_GET_LINE  0  ::::\n");
		return (0);
	}


	if (DEBUG && DEBUG_GET_LINE)
		dprintf(1, "::::     END_GET_LINE  1  ::::\n");
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	t_dfile	*lst = 0;
	t_dfile			*elem;
	t_dfile			*prev;
	int				error;

	if (DEBUG && DEBUG_GET_NEXT_LINE)
			dprintf(1, "::::       GET_LINE      ::::\n");

	prev = NULL;
	elem = get_right_fd(&lst, fd, &prev);
	if ((error = get_line(elem, prev, line)) != 1)
	{
		if (DEBUG && DEBUG_GET_NEXT_LINE)
		{
			if (PRINT_RETURN)
			{
				dprintf(1, "return:|%s|\n", *line);
			}
			dprintf(1, "::::     END_GET_LINE %d   ::::\n", error);
		}
		return (error);
	}
	if (DEBUG && DEBUG_GET_NEXT_LINE)
	{
			if (PRINT_RETURN)
			{
				dprintf(1, "return:|%s|\n", *line);
			}
			dprintf(1, "::::     END_GET_LINE 0   ::::\n");
	}
	return (1);
}
