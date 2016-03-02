/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/25 01:32:19 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_strmalloc(int size)
{
	char	**tab;

	tab = ft_memalloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	static	int	nb;
	char		**tab;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i + j] && s[i + j] != c)
		j++;
	nb += (j) ? 1 : 0;
	if (!s[i + j])
		tab = ft_strmalloc(nb);
	else
		tab = ft_strsplit(s + i + j, c);
	if (!tab)
		return (NULL);
	if (j)
		tab[--nb] = ft_strncpy(ft_strnew(j), s + i, j);
	else
		tab[nb] = 0;
	return (tab);
}
