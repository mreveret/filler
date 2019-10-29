/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:54:10 by machoffa          #+#    #+#             */
/*   Updated: 2019/10/16 17:59:51 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	if (s[i] == '\0')
		return (0);
	j = 1;
	while (s[i])
	{
		if (s[i + 1] == c)
			j++;
		while (s[i + 1] && s[i + 1] == c)
			i++;
		i++;
	}
	return (j);
}

static int		start_word(const char *s, int i, char c)
{
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static int		count_letter(const char *s, int i, char c)
{
	int k;

	k = 0;
	while (s[i] && s[i] != c)
	{
		k++;
		i++;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	char	*str;

	i = 0;
	str = ft_strtrimc(s, c);
	if ((!(str) || !(c)))
		return (NULL);
	j = count_word(str, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (j + 1))))
		return (NULL);
	j = -1;
	while (++j < count_word(str, c))
	{
		k = count_letter(str, i, c);
		if (!(tab[j] = (char *)ft_memalloc(sizeof(char) * (k + 1))))
			return (NULL);
		tab[j] = ft_strncpy(tab[j], str + i, k);
		i = start_word(str, i, c);
	}
	free(str);
	tab[j] = 0;
	return (tab);
}
