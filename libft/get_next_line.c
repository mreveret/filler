/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:31:35 by mreveret          #+#    #+#             */
/*   Updated: 2019/09/24 16:14:58 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static int			read_return(int fd, char **line, char **tab, int ret)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	if (ret == 0 && (tab[fd] == NULL || tab[fd][0] == '\0'))
		return (0);
	while (tab[fd] && tab[fd][i] && tab[fd][i] != '\n')
		i++;
	if (tab[fd] && tab[fd][i] == '\n')
	{
		*line = ft_strsub(tab[fd], 0, i);
		tmp = tab[fd];
		tab[fd] = ft_strdup(tmp + i + 1);
		ft_strdel(&tmp);
		if (tab[fd][0] == '\0')
			ft_strdel(&tab[fd]);
	}
	else if (tab[fd] && tab[fd][i] == '\0')
	{
		*line = ft_strdup(tab[fd]);
		ft_strdel(&tab[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tab[OPEN_MAX];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	buff[0] = '\0';
	ret = 0;
	if (!line || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (!tab[fd])
		tab[fd] = ft_strnew(0);
	while (!(ft_strchr(buff, C)) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tab[fd] = ft_strjoin_free(tab[fd], buff, 1);
	}
	return (read_return(fd, line, tab, ret));
}
