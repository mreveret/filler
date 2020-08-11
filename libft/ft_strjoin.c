/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:12:53 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:22:41 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (ft_strnew(0));
	if (!(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - 1)))
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}
