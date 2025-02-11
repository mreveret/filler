/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:47:18 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:21:41 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]) == 1)
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	if (ft_islower(str[i]) == 1)
		str[i] = str[i] - 32;
	while (str[i])
	{
		if ((ft_isspace(str[i]) == 1 || str[i] == '-' || str[i] == '+')
				&& ft_islower(str[i + 1]) == 1)
			str[i + 1] = str[i + 1] - 32;
		i++;
	}
	return (str);
}
