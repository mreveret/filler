/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:44:31 by mreveret          #+#    #+#             */
/*   Updated: 2019/10/23 19:41:00 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "filler.h"

void			tabinit(t_struct *f, int **tab)
{
	int		i;
	int		j;

	i = 0;
	while (++i < f->h + 1 && (j = 3))
	{
		while (++j < f->w + 4)
		{
			if (f->p == 1 && findone(f->tab1[i][j], "xX") == 1)
				tab[i - 1][j - 4] = -1;
			if (f->p == 1 && findone(f->tab1[i][j], "oO") == 1)
				tab[i - 1][j - 4] = 1000;
			if (f->p == 2 && findone(f->tab1[i][j], "oO") == 1)
				tab[i - 1][j - 4] = -1;
			if (f->p == 2 && findone(f->tab1[i][j], "xX") == 1)
				tab[i - 1][j - 4] = 1000;
			if (f->tab1[i][j] == '.')
				tab[i - 1][j - 4] = 0;
		}
	}
}

static void		map3(t_struct *f, int i, int j, int **tab)
{
	int		k;
	int		k2;
	int		l;
	int		m;

	l = i - 1;
	m = j - 4;
	k = 1;
	while (++m < f->w)
	{
		if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
			tab[l][m] = k;
		k2 = -1;
		while (++k2 < k && ++l < f->h)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		k2 = -1;
		l = i - 1;
		while (++k2 < k && --l >= 0)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		l = i - 1;
		k++;
	}
}

static void		map2(t_struct *f, int i, int j, int **tab)
{
	int		k;
	int		k2;
	int		l;
	int		m;

	l = i - 1;
	m = j - 4;
	k = 1;
	while (--m >= 0)
	{
		if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
			tab[l][m] = k;
		k2 = -1;
		while (++k2 < k && ++l < f->h)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		k2 = -1;
		l = i - 1;
		while (++k2 < k && --l >= 0)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		l = i - 1;
		k++;
	}
	map3(f, i, j, tab);
}

static void		map1(t_struct *f, int i, int j, int **tab)
{
	int		k;
	int		k2;
	int		l;
	int		m;
	l = i - 1;
	m = j - 4;
	k = 1;
	while (++l < f->h)
	{
		if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
			tab[l][m] = k;
		k2 = -1;
		while (++k2 < k && ++m < f->w)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		k2 = -1;
		m = j - 4;
		while (++k2 < k && --m >= 0)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		m = j - 4;
		k++;
	}
	map2(f, i, j, tab);
}

void			map(t_struct *f, int i, int j, int **tab)
{
	int		k;
	int		k2;
	int		l;
	int		m;

	l = i - 1;
	m = j - 4;
	k = 1;
	while (--l >= 0)
	{
		if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
			tab[l][m] = k;
		k2 = -1;
		while (++k2 < k && ++m < f->w)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		k2 = -1;
		m = j - 4;
		while (++k2 < k && --m >= 0)
			if (tab[l][m] == 0 || (tab[l][m] > k && tab[l][m] < 1000))
				tab[l][m] = k;
		m = j - 4;
		k++;
	}
	map1(f, i, j, tab);
}
