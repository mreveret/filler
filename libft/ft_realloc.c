/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:17:58 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:21:15 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *str, int size)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	new = ft_strcpy(new, str);
	free(str);
	return (new);
}
