/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/25 01:33:23 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*copy;
	size_t	i;

	if (s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		i = 0;
		while (s[i])
			i++;
		while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t' ||
				s[i - 1] == '\n'))
			i--;
		if (i == 0)
			return (NULL);
		copy = ft_strnew(i + 1);
		if (!copy)
			return (NULL);
		copy = ft_strncpy(copy, s, i);
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
