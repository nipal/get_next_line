/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:06:10 by fjanoty           #+#    #+#             */
/*   Updated: 2016/09/08 02:27:01 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define MAX	10
#define LEN 6

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
		while ((i < MAX))
		{
			fd[i] = -1;
			if (i < MAX && i < (ac - 1))
			{
				fd[i] = open(av[i + 1], O_RDONLY);
				dprintf(1, "i:%d\n", i);
				if ((fd[i]) < 0)
				{
				ft_putstr("ERROR FROM fIlE DESCRIPTOR\n");
				}
			}
			i++;
		}
		i = 0;
		while (i < LEN)
		{
			j = 0;
			while (fd[j] >= 0 && j < MAX && j < (ac - 1))
			{
				if (fd[j] > 0)
				{
					ret = get_next_line(99, NULL);
					if (ret != 0)
						dprintf(1, "index:%d	fd:[%d]	----->[%s]	ret:%d\n",j, fd[j], str, ret);
					else
						dprintf(1, "index:%d	fd:[%d]	ret:	%d\n", j, fd[j], ret);
				}
				j++;
			}
			i++;
		}
		j = 0;
		while (j < MAX && j < (ac - 1))
		{
			close(fd[j]);
			j++;
		}
	}
	return (0);
}
