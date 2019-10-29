/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreveret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:49:50 by mreveret          #+#    #+#             */
/*   Updated: 2019/10/16 18:34:36 by mreveret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft.h"

int		get_next_line(const int fd, char **line);
# ifndef BUFF_SIZE

#  define BUFF_SIZE 5

# endif

# ifndef STOPPER

#  define C '\n'

# endif

#endif
