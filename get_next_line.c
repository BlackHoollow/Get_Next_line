/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/08 22:21:33 by nromptea         ###   ########.fr       */
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
		ft_putendl("coucou");
	return (0);
}

int		ft_read(char **rest, int fd)
{
	int		ret;
	char	*buff;
	char	*swp;
	char	*c;

	buff = ft_strnew(BUFF_SIZE);
	while (!(c = ft_strchr(*rest, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		ft_putendl("coucou");
		buff[ret] = '\0';
		swp = *rest;
		*rest = ft_strjoin(swp, buff);
		ft_strdel(&swp);
	}
	ft_strdel(&buff);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !c)
		return (0);
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
	static char		*rest;
	int				ret;
	char			*swp;

	ret = ft_read(&rest, fd);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		*line = rest;
		rest = NULL;
		return (0);
	}
	*line = first_line(rest);
	swp = rest;
	rest = ft_strdup(ft_strchr(rest, '\n') + 1);
	ft_strdel(&swp);
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
