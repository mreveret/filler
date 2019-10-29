/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:57:00 by mreveret          #+#    #+#             */
/*   Updated: 2019/10/23 19:37:45 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int     main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int     i;
    int     j;
    t_env f;
    char    *line;
    i = -1;
    j = -1;
    f.p = 0;
    while (get_next_line(0, &line) > 0)
    {
        if (ft_strlen(line) > 10 && ft_strstr(line, "$$$ exec p"))
        {
            if (ft_strstr(line, "machoffa"))
            {
                f.p = ft_atoi(line + 10);
                f.c = f.p == 1 ? 'O' : 'X';
            }
            continue ;
        }
        if (ft_strlen(line) > 8 && ft_strstr(line, "Plateau "))
        {
            while (!ft_isdigit(*line))
                line++;
            f.h = ft_atoi(line);
            while (ft_isdigit(*line))
                line++;
            f.w = ft_atoi(line);
            if (!(f.tab1 = (char **)malloc(sizeof(char *) * f.h + 1)))
                return (-1);
            continue ;
        }
        if (++i < f.h + 1)
        {
            if (!(f.tab1[i] = (char *)malloc(sizeof(char) * ft_strlen(line))))
                return (-2);
            f.tab1[i] = ft_strncpy(f.tab1[i], line, f.w + 4);
            continue ;
        }
//      if (i == f.h + 1)
//      {
//          f.tab1[i] = 0;
//          continue ;
//      }
        if (ft_strlen(line) > 6 && ft_strstr(line, "Piece "))
        {
            while (!ft_isdigit(*line))
                line++;
            f.hp = ft_atoi(line);
            while (ft_isdigit(*line))
                line++;
            f.wp = ft_atoi(line);
            if (!(f.tab2 = (char **)malloc(sizeof(char *) * f.hp)))
                return (-3);
            continue ;
        }
        if (++j < f.hp)
        {
            if (!(f.tab2[j] = (char *)malloc(sizeof(char) * ft_strlen(line))))
                return (-4);
            f.tab2[j] = ft_strncpy(f.tab2[j], line, f.wp);
            continue ;
        }
        if (j >= f.hp)
            break ;
    }
    filler(&f);
    return (0);
}
