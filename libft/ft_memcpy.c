/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:41:09 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:20:09 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		cpy_dst[i] = cpy_src[i];
		i++;
		n--;
	}
	return ((void *)cpy_dst);
}
