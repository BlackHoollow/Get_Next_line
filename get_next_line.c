/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/16 21:37:15 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *buff, char *cpy_buff, char *rest)
{
	int		ret;

	if (!(ft_strchr(rest, '\n')))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (read > 0)
			return (NULL);
		cpy_buff = ft_strjoin(cpy_buff, buff);
		while (!(ft_strchr(buff, '\n')))
		{
			ret = read(fd, buff, O_RDONLY);
			cpy_buff = ft_strjoin(cpy_buff, buff);
		}
	}
	else
		return (rest);
	return (NULL);
}


char	*get_next_line(int const fd, char **line)
{
	char		*buff;
	static char	*rest = NULL;
	char		*cpy_buff;
	int			read;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buff == NULL)
		return (NULL);
	cpy_buff = ft_read(fd, buff, cpy_buff, rest);
	*line = ft_strchr(cpy_buff, '\n');
	rest = ft_strsub(rest, ft_strlen(*line), (ft_strlen(cpy_buff) - ft_strlen(*line)));
	ft_putstr(*line);
	return (*line);
}

int	main(int argc, char **argv)
{
	char	**line;
	int		fd;

	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, line);
	}
	return (0);
}
