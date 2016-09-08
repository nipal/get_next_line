/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:06:10 by fjanoty           #+#    #+#             */
/*   Updated: 2016/09/06 10:18:09 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define MAX	10

int	main(int ac, char **av)
{
	char	*str;
	int		fd[MAX];
	int		ret;
	int		i;
	int		j;

	str = NULL;
	ret = 1;
	if (ac > 1)
	{
		i = 0;
		while (i < MIN(MAX, (ac - 1)))
		{
			dprintf(1, "MAX:%d	(ac - 1):%d	MIN:%d\n", MAX, (ac - 1), MIN(MAX, (ac - 1)));
			fd[i] = -1;
			fd[i] = open(av[i], O_RDONLY);
			dprintf(1, "i:%d\n", i);
			if ((fd[i]) < 0)
			{
				ft_putstr("ERROR FROM fIlE DESCRIPTOR\n");
			}
			i++;
		}
		i = 0;
		while (i < 30)
		{
			j = 0;
			while (fd[j] >= 0 && j < MIN(MAX, ac - 1))
			{
				ret = get_next_line(fd[j], &str);
				if (ret != 0)
					dprintf(1, "fd:[%d]	----->[%s]	ret:%d\n", fd[j], str, ret);
				else
					dprintf(1, "fd:[%d]	ret:	%d\n", fd[j], ret);
				j++;
			}
			i++;
		}
		j = 0;
		while (j < MIN(MAX, ac - 1))
		{
			close(fd[j]);
			j++;
		}
	}
	return (0);
}
