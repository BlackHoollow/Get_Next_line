/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:23:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/09 14:28:18 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000000

int		ft_read(int fd, char *rest[fd]);
char	*first_line(char *cpy_buff);
int		get_next_line(int const fd, char **line);

#endif
