/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:25:19 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:19:56 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy_s;

	cpy_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cpy_s[i] == (unsigned char)c)
			return (cpy_s + i);
		i++;
	}
	return (NULL);
}
