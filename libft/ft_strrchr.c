/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:22 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:23:42 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if ((char)c == s[j])
		return ((char *)s + j);
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
