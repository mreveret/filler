/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:44:29 by mreveret          #+#    #+#             */
/*   Updated: 2019/10/23 20:39:48 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_piece(t_env *f)
{
	int i;
	int j;

	i = 0;
	if (f->x + (f->wp - f->e->x ) > f->w || f->x - (f->e->x) < 0)
		return (0);
	if (f->y + (f->hp - f->e->y ) > f->h || f->y - (f->e->y) < 0)
		return (0);
	while (i < f->h - f->y)
	{
		j = 0;
		while (j < f->w -f-> x)
		{
			if (f->tab1[f->y - i] [(f->x) + j] == 'X' ||f->tab1[f->y - i] [(f->x) + j] == 'O')
				return (0);
			j++;
		}
	i++;
	}
	
	return (1);
}
