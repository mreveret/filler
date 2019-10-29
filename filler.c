/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:38:22 by mreveret          #+#    #+#             */
/*   Updated: 2019/10/23 20:36:02 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void print_words_tables(char **tab, int si)
{
    int i;
    int j;
    i = 0;
    while (i < si)
    {
        j = 0;
        while (tab[i][j])
        {
            ft_putchar(tab[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}
static void init(t_env *f)
{
    int     i;
    int     j;
    i = -1;
    while (++i < f->h + 1)
    {
        j = -1;
        while (f->tab1[i][++j])
            if (f->tab1[i][j] == f->c)
                break ;
    }
    f->x = j;
    f->y = i;
    tab_opti(f);
}
void        filler(t_env *f)
{
    init(f);
    check_piece(f);
    print_words_tables(f->tab1, f->h + 1);
    print_words_tables(f->tab2, f->hp);
}
