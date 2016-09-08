/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:02:25 by fjanoty           #+#    #+#             */
/*   Updated: 2016/09/08 02:37:19 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strmchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (0);
	if (c == 0)
		return (ft_strlen(s));
	p = ft_strchr(s, c);
	if (p)
	{
		return ((int)(p - s));
	}
	return (ft_strlen(s));
}

char		*ft_str_magic(char *str1, char *str2)
{
	int		max1;
	int		max2;
	char	*result;

	if (!str1 || !str2)
		return (NULL);
	max1 = ft_strmchr(str1, '\n');
	max2 = ft_strmchr(str2, '\n');
	if (!(result = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	ft_strncat(result, str1, max1);
	ft_strncat(result + ft_strlen(str1), str2, max2);
	free(str1);
	return (result);
}

char		*str_line2(int fd, char **rest, int *ret)
{
	int		again;
	char	*line;
	char	*buffer;
	char	*tmp;

	line = ft_strnew(BUFF_SIZE);
	buffer = ft_strnew(BUFF_SIZE);
	ft_memmove(buffer, *rest, MIN(ft_strlen(*rest), BUFF_SIZE));
	tmp = ft_strnew(BUFF_SIZE);
	buffer = ft_strcpy(buffer, *rest);
	again = (!(ft_strchr(buffer, '\n')));
	line = ft_strncpy(line, buffer, ft_strmchr(buffer, '\n'));
	*ret = 1;
	while (again == 1)
	{
		ft_bzero(buffer, BUFF_SIZE);
		*ret = read(fd, buffer, BUFF_SIZE);
		line = ft_str_magic(line, buffer);
		again = ((!(ft_strchr(buffer, '\n'))) && *ret == BUFF_SIZE);
	}
	*rest = ft_strcpy(tmp, buffer + 1 + ft_strmchr(buffer, '\n'));
	free(buffer);
	return (line);
}

t_fdgnl		*get_creat_elem(t_fdgnl **begin, int fd)
{
	t_fdgnl	*elem;

	if (!begin)
		return (NULL);
	elem = *begin;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (!elem)
	{
		if (!(elem = (t_fdgnl*)malloc(sizeof(t_fdgnl))))
			return (NULL);
		elem->fd = fd;
		elem->rest = ft_strnew(BUFF_SIZE);
		elem->next = *begin;
		*begin = elem;
	}
	return (elem);
}

int			get_next_line(int fd, char **line)
{
	static	t_fdgnl	*begin = NULL;
	t_fdgnl			*elem;
	char			*str;
	int				ret;

	ret = 1;
	if (fd < 0)
		return (-1);
	if (!line)
	{
//		dprintf(1, "nooooon\n");
		return (0);
	}
	elem = get_creat_elem(&begin, fd);
	str = str_line2(elem->fd, &(elem->rest), &ret);
	*line = str;
	if (ret < 0)
		return (-1);
	return ((ft_strlen(*line) > 0));
}
