/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:23:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/07 19:04:07 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

int		is_backslash(char *str);
int		ft_read(char **cpy_buff, char *rest, int fd);
char	*first_line(char *cpy_buff);
int		get_next_line(int const fd, char **line);

#endif
