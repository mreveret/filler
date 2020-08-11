/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:43:34 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:23:59 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(j = ft_strlen(s) - 1))
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if (!(dst = ft_strnew(j - i + 1)))
		return (NULL);
	ft_strncpy(dst, s + i, j - i + 1);
	return (dst);
}
