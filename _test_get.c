/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 07:59:41 by fjanoty           #+#    #+#             */
/*   Updated: 2016/03/03 08:06:56 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_next_line(int const fd, char **line);

int	main(void)
{
	char	*str;
	while (get_next_line(0, &str) > 1)
		dprintf(1, "%s\n", str);
	return (0);
}
