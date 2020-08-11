/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:30:52 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:20:19 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	i;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if (src_cpy < dst_cpy)
	{
		while (i < len)
		{
			dst_cpy[len - i - 1] = src_cpy[len - i - 1];
			i++;
		}
	}
	else
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	return ((void *)dst_cpy);
}
