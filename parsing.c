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
#include "./libft/libft.h"
#include "filler.h"

}

void		nb_col(t_env *e)
{
	int		nb_lines;

	e->max_width = 0;
	nb_lines = e->max_h;
	if (!(e->tab = (char **)malloc(sizeof(char *) * e->max_h)))
		return ;
	while (nb_lines > 0)
	{
		if (!(e->tab[--nb_lines] = (char*)malloc(sizeof(char) * e->max_width)))
			return ;
	}
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void		parsing(t_env *e)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
	if (strncmp())
	}
}
