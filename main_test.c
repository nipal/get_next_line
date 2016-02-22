/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 02:15:45 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/22 15:20:38 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		end;
	int		i;
	int		line = 0;

	i = 0;
	while ((end = get_next_line(0, &str)) == 1 && i >= 0)
	{
		dprintf(1, "===LINE:===--> %d	", line++);
		dprintf(1, "|%s|\n", (str));
i++;
	}
		dprintf(1, "===LINE:===--> %d	", line++);
		dprintf(1, "|%s|\n", (str));
	return (0);
}


//	et les ligne se copie mal (comme si on ne copiai que la dernier parti)
