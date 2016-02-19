/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_uniom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:46:01 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 21:24:39 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

typedef	unsigned	long	t_ulong;
typedef	unsigned	char	t_uchar;
typedef	union	u_ochar
{
	t_ulong		bin_data;
	char		char_data[8];
}				t_ochar;


void	print_memory(t_ochar *data, int	size)
{
	int	i;
	int	osize;
	int	size2;

	i = 0;
	osize = ((size) / 8);
	size2 = sizeof(t_ochar);

	dprintf(1, "SIZE1:%d\n", size);
	dprintf(1, "SIZE2:%d\n", size2);
	dprintf(1, "osize:%d\n", osize);
	i = 0;
	while (i < ((size + 1) / 8) + 1)
	{
	size2 = (size - (8 * (i)) >= 8) ? 8 : (size % 8); 
	dprintf(1, "\nsize:%d word:%d	", size2, i);
		write(1, data, size2);
		data++;
		i++;
	}
//	size2 = 8 - (size - (8 * i)) * 2;
//	write(1, data, size2);
}

void	push_memory(void *mem)
{
	t_ochar	*tab;
	unsigned	char	*test;

	test = (unsigned char*) mem;
//	print_memory
//	tab = 
}

int	main(int ac, char ** av)
{
	char *str;

	str = ft_strdup("Le caca  c'est delicieux");
	if (ac == 1)
		print_memory((t_ochar*)str, ft_strlen(str));
	else if (ac >= 2)
	{
		print_memory((t_ochar*)av[1], ft_strlen(av[1]));
	}
	return (0);
}
