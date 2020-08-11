/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:08:13 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:23:04 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		dst[i] = (*f)(s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
