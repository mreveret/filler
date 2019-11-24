/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabopti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machoffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:48 by machoffa          #+#    #+#             */
/*   Updated: 2019/10/23 19:35:04 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		tab_opti2(t_struct *f)
{
	int i;
	int j;
	int k;
	
	j = 0;
	i = 0;
	while (i < f->h_p && f->tab2[i][0] == '.')
		i++;
	if (i == f->h_p)
	{
		i = -1;
		k = j;
		while (++i < f->h_p)
		{
			while (j < f->w_p)
			{
				f->tab2[i][j] = f->tab2[i][j + 1];
				j++;
			}
			j = k;
		}
		f->w_p--;
		tab_opti2(f);
	}
}

void			tab_opti(t_struct *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < f->w_p && f->tab2[0][j] == '.')
		j++;
	if (j == f->w_p)
	{
		free(f->tab2[0]);
		while (i + 1 < f->h_p)
		{
			f->tab2[i] = f->tab2[i + 1];
			i++;
		}
		f->h_p--;
		f->tab2[i] = 0;
		tab_opti(f);
	}
	tab_opti2(f);
}
