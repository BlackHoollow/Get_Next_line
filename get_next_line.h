/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:23:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/06 14:09:03 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42 

char	*ft_read_all(char *cpy_buff, int fd);
char	*first_line(char *cpy_buff);
char	*cut_line(char *cpy_buff);
int		get_next_line(int const fd, char **line);

#endif
