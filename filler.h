/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:41:43 by mreveret          #+#    #+#             */
/*   Updated: 2019/10/23 20:36:23 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef filler_h

# define filler_h
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_pivot
{
	int			x;
	int			y;
}				t_pivot;

typedef struct	s_piece
{
	int			hp;
	int			wp;
	char		**tab2;
	t_pivot		*p;
}				t_piece;

typedef struct	s_env
{
	char		**tab1;
	char		**tab2;
	int			h;
	int			w;
	int			hp;
	int			wp;
	int			p;
	int			c;
	int			x;
	int			y;
	t_pivot		*e;
}				t_env;

	
static void		print_words_tables(char **tab, int si);
void			filler(t_env *f);
static void		init(t_env *f);
static void		tab_opti2(t_env *f);
void			tab_opti(t_env *f);
int				check_piece(t_env *f);
#endif

