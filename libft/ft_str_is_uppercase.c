/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:41:33 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:21:36 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isupper(str[i]))
			return (0);
		i++;
	}
	return (1);
}
