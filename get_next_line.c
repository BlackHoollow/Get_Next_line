/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/07 19:26:29 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		is_backslash(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_read(char **cpy_buff, char *rest, int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	
	if ((is_backslash(rest) == 0))
	{
		while (is_backslash(buff) == 0)
		{
			ret = read(fd, buff, BUFF_SIZE);
			if (ret == 0)
				return (0);
			if (ret < 0)
				return (-1);
			buff[ret] = '\0';
			tmp = ft_strjoin(tmp, buff);
		}
	}
	*cpy_buff = tmp;
	return (1);
}

char	*first_line(char *cpy_buff)
{
	int		i;
	char	*line;

	i = 0;
	while (cpy_buff[i] != '\n')
		i++;
	line = ft_strsub(cpy_buff, 0, i);
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	char			*cpy_buff;
	static char		*rest = NULL;
	int				ret;

	cpy_buff = NULL;
	ret = ft_read(&cpy_buff, rest, fd);
	if (ret == -1)
		return (-1);
	*line = first_line(cpy_buff);
	rest = ft_strchr(cpy_buff, '\n') + 1;
	if (ret == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	ret;
	char	*line;

	line = (char *)malloc(sizeof(char) * 100);
	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		ret = get_next_line(fd, &line);
		ft_putendl(line);
	}
	return (0);
}
