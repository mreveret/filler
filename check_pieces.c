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

static void		check2(t_struct *f, int **tab)
{
	while (f->j < f->w_p)
	{
		if (f->tab2[f->i][f->j] == '*')
		{
			if (f->y2 - 4 >= f->w || f->x2 - 1 >= f->h
					|| tab[f->x2 - 1][f->y2 - 4] == -1)
			{
				f->tmp2 = -1;
				f->tmp = 0;
				return ;
			}
			else
			{
				f->tmp2 = 0;
				f->tmp += tab[f->x2 - 1][f->y2 - 4];
			}
		}
		f->y2++;
		f->j++;
	}
}

static void		check1(t_struct *f, int **tab)
{
	while (f->i < f->h_p)
	{
		f->j = 0;
		f->y2 = f->y1;
		check2(f, tab);
		if (f->tmp2 == -1)
		{
			f->tmp2 = 0;
			return ;
		}
		f->x2++;
		f->i++;
	}
}

static void		init(t_struct *f)
{
	f->i = 0;
	f->j = 0;
	f->x1 = 1;
	f->tmp = 0;
	f->tmp2 = 0;
	f->a = 0;
	f->h_f = 0;
	f->w_f = 0;
}

int			check_pieces(t_struct *f, int **tab)
{
	init(f);
	while (f->x1 < f->h + 1)
	{
		f->y1 = 4;
		while (f->y1 < f->w + 4)
		{
			f->i = 0;
			f->x2 = f->x1;
			check1(f, tab);
			if (f->i == f->h_p && f->j == f->w_p && f->tmp > 1000
					&& f->tmp < 2000 && (f->a == 0 || (f->p == 1
					&& f->a > f->tmp) || (f->p == 2 && f->a >= f->tmp)))
			{
				f->a = f->tmp;
				f->h_f = f->x1;
				f->w_f = f->y1;
			}
			f->tmp = 0;
			f->y1++;
		}
		f->x1++;
	}
	return (1);
}
