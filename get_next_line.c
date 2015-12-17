/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/17 16:56:34 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_read(int fd, char *buff, char *cpy_buff, char *rest)
{
	int			ret;

	if ((ft_strchr(rest, '\n') == NULL) &&
			(ret = read(fd, buff, BUFF_SIZE) > 0))
	{
		cpy_buff = ft_strjoin(cpy_buff, rest);
		while ((ft_strchr(buff, '\n') == NULL))
		{
			if ((ret = read(fd, buff, O_RDONLY)) > 0)
				cpy_buff = ft_strjoin(cpy_buff, buff);
			else
				return (NULL);
		}
		return (cpy_buff);
	}
	else if ((ft_strchr(rest, '\n') != NULL))
		return (rest);
	return (NULL);
}

char	*ft_choppe_first(char *cpy_buff)
{
	char	*line;
	int		len;

	len = 0;
	while (cpy_buff[len] != '\n')
		len++;
	line = ft_strnew(len - 1);
	line = ft_strncpy(line, cpy_buff, len - 1);
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	char		*buff;
	static char	*rest = NULL;
	char		*cpy_buff;

	cpy_buff = NULL;
	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buff == NULL)
		return (-1);
	cpy_buff = ft_read(fd, buff, cpy_buff, rest);
	if (cpy_buff == NULL)
		return (0);
	rest = ft_strdup((ft_strchr(cpy_buff, '\n')) + 1);
	*line = ft_choppe_first(cpy_buff);
	ft_strdel(cpy_buff);
	return (1);
}
