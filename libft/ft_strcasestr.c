/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:53:59 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:21:51 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && (needle[j] == haystack[i + j]
					|| (ft_islower(needle[j]) && needle[j]
						== haystack[i + j] + 32) || (ft_isupper(needle[j])
							&& needle[j] == haystack[i + j] - 32)))
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
