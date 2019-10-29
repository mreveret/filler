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
static void    tab_opti2(t_env *f)
{
	int i;
	int j;
	int k;
	j = 0;
	while (j < f->wp)
	{
		i = -1;
		while (++i < f->hp && f->tab2[i][j] == '.')
			;
		if (i == f->hp)
		{
			i = -1;
			k = j;
			while (++i < f->hp)
			{
				while (j < f->wp)
				{
					f->tab2[i][j] = f->tab2[i][j + 1];
					j++;
				}
				j = k;
			}
			f->wp--;
			j = 0;
		}
		else
			j++;
	}
}
void		tab_opti(t_env *f)
{
	int i;
	int j;
	i = 0;
	while (i < f->hp)
	{
		j = -1;
		while (++j < f->wp - 1 && f->tab2[i][j] == '.')
		{
			//			printf("%d\n", i);
			;
		}
		if (j == f->wp - 1)
		{
			free(f->tab2[i]);
			while (i + 1 < f->hp)
			{
				f->tab2[i] = f->tab2[i + 1];
				i++;
			}
			f->hp--;
			f->tab2[i] = 0;
			i = 0;
		}
		else
			i++;
	}
	tab_opti2(f);
}
