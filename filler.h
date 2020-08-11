/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:10:08 by mreveret          #+#    #+#             */
/*   Updated: 2019/11/25 20:44:33 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_struct
{
	int			a;
	int			p;
	char		m;
	char		**tab1;
	int			h;
	int			w;
	int			h_p;
	int			w_p;
	int			h_f;
	int			w_f;
	int			x;
	int			y;
	char		**tab2;
	int			f;
	int			f2;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			tmp;
	int			tmp2;
	int			i;
	int			j;
	int			i1;
	int			j1;
}				t_struct;

int				main(void);
int				filler(t_struct *f);
void			tab_opti(t_struct *f);
int				check_pieces(t_struct *f, int **tab);
void			map(t_struct *f, int i, int j, int **tab);
int				findone(char c, char *s);
void			tabinit(t_struct *f, int **tab);

#endif
