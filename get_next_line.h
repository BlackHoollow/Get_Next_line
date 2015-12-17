/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:23:11 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/17 16:26:08 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

char	*ft_read(int fd, char *buff, char *cpy_buff, char *rest);
char	*ft_choppe_first(char *cpy_buff);
int		get_next_line(int const fd, char **line);

#endif
