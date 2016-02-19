/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 02:15:45 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/18 02:24:21 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		back;

	back = get_next_line(0, &str);
	dprintf(1, "%s\noct:%d\n", str, back);
}
