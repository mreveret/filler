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
int             findone(char c, char *s)
{
    int i;
    i = -1;
    if (!(s) || !(c))
        return (0);
    while (s[++i])
        if (s[i] == c)
            return (1);
    return (0);
}
static void     init2(t_struct *f, int **tab)
{
    int i;
    int j;
    i = 0;
    while (++i < f->h + 1)
    {
        j = 3;
        while (++j < f->w + 4)
        {
            if (f->p == 1)
            {
                if (findone(f->tab1[i][j], "xX") == 1)
                    map(f, i, j, tab);
            }
            if (f->p == 2)
            {
                if (findone(f->tab1[i][j], "oO") == 1)
                    map(f, i, j, tab);
            }
        }
    }
}
static void     init(t_struct *f)
{
    int     i;
    int     **tab;
    if (!(tab = (int **)malloc(sizeof(int *) * f->h)))
        return ;
    i = -1;
    while (++i < f->h)
        if (!(tab[i] = (int *)malloc(sizeof(int) * f->w)))
            return ;
    tabinit(f, tab);
    init2(f, tab);
    tab_opti(f);
    check_pieces(f, tab);
    i = -1;
    while (++i < f->h)
        free(tab[i]);
    free(tab);
}
int             filler(t_struct *f)
{
    int i;
    int tmp;
    int tmp2;
    tmp = f->h_p;
    tmp2 = f->w_p;
    init(f);
    tmp -= f->h_p;
    tmp2 -= f->w_p;
    ft_putnbr(f->h_f - 1 - tmp);
    ft_putchar(' ');
    ft_putnbr(f->w_f - 4 - tmp2);
    ft_putchar('\n');
    f->h = 0;
    f->w = 0;
    f->h_p = 0;
    f->w_p = 0;
    i = -1;
    return (1);
}
