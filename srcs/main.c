/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:13:11 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:40:29 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		reading3(t_struct *f, char *l, int i, int j)
{
	if (i == 1)
	{
		while (!ft_isdigit(*l))
			l++;
		f->h_p = ft_atoi(l);
		while (ft_isdigit(*l))
			l++;
		f->w_p = ft_atoi(l);
		if (!(f->tab2 = (char **)malloc(sizeof(char *) * f->h_p)))
			return (-3);
	}
	if (i == 2)
	{
		if (!(f->tab2[j] = (char *)malloc(sizeof(char) * (ft_strlen(l) + 1))))
			return (-4);
		f->tab2[j] = ft_strncpy(f->tab2[j], l, f->w_p);
	}
	return (1);
}

static int		reading2(t_struct *f, char *l, int i, int j)
{
	if (j == 1)
	{
		while (!ft_isdigit(*l))
			l++;
		f->h = ft_atoi(l);
		while (ft_isdigit(*l))
			l++;
		f->w = ft_atoi(l);
		if (!(f->tab1 = (char **)malloc(sizeof(char *) * f->h + 1)))
			return (-1);
	}
	if (j == 2)
	{
		if (!(f->tab1[i] = (char *)malloc(sizeof(char) * (ft_strlen(l) + 1))))
			return (-2);
		f->tab1[i] = ft_strncpy(f->tab1[i], l, f->w + 4);
	}
	return (1);
}

static void		test(t_struct *f, char *line)
{
	if (ft_strlen(line) > 8 && ft_strstr(line, "Plateau ")
			&& reading2(f, line, f->i1, 1))
		return ;
	if (f->h > 0 && ++f->i1 < f->h + 1 && reading2(f, line, f->i1, 2))
		return ;
	if (ft_strlen(line) > 6 && ft_strstr(line, "Piece ")
			&& reading3(f, line, 1, f->j1))
		return ;
	if (f->h_p > 0 && ++f->j1 < f->h_p && reading3(f, line, 2, f->j1))
	{
		if (f->j1 == f->h_p - 1 && filler(f) && (f->i1 = -1))
			f->j1 = -1;
		return ;
	}
}

static void		reading(t_struct *f)
{
	char		*line;

	f->i1 = -1;
	f->j1 = -1;
	if (get_next_line(0, &line) > 0 && ft_strlen(line) > 10
			&& ft_strstr(line, "$$$ exec p"))
	{
		if (ft_strstr(line, "mreveret") && (f->p = ft_atoi(line + 10)))
			f->m = f->p == 1 ? 'O' : 'X';
		free(line);
	}
	while (get_next_line(0, &line) > 0)
	{
		test(f, line);
		free(line);
	}
}

int				main(void)
{
	t_struct	f;

	f.p = 0;
	f.h = 0;
	f.w = 0;
	f.h_p = 0;
	f.w_p = 0;
	reading(&f);
	return (0);
}
