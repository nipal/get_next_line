/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 02:15:45 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/22 10:05:45 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		end;
	int		i;

	i = 0;
	while ((end = get_next_line(0, &str)) == 1 && i >= 0)
	{
		dprintf(1, "	>>>>>>>>>>>>end:%d<<<<<<<<<<<<<<\n", end);
//		dprintf(1, "%ld\n", (long)*(str));
dprintf(1, "################line:|%s|\n", (str));
i++;
	}
		dprintf(1, "	<<<<<<<<<<  end:%d  >>>>>>>>>>>>\n", end);
dprintf(1, "################final_line:|%s|\n", (str));
	printf("end whith:%d\n", end);
	return (0);
}


//	il ne faut pas ajouter le '\n' a la ligne lu
//	et les ligne se copie mal (comme si on ne copiai que la dernier parti)
