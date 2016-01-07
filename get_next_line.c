/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/07 16:22:23 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_read_all(char *cpy_buff, int fd)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while (42)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret <= 0)
			break ;
		buff[ret] = '\0';
		tmp = cpy_buff;
		if (!(cpy_buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + ret + 1))))
			return (NULL);
		if (tmp == NULL)
			ft_strcpy(cpy_buff, buff);
		else
		{
			ft_strcpy(cpy_buff, tmp);
			ft_strcat(cpy_buff, buff);
			free(tmp);
		}
	}
	return (cpy_buff);
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

	cpy_buff = NULL;
	if (fd < 0)
		return (-1);
	if (rest == NULL)
		cpy_buff = ft_read_all(cpy_buff, fd);
	else
		cpy_buff = rest;
	*line = first_line(cpy_buff);
	rest = ft_strchr(cpy_buff, '\n') + 1;
	if (rest != NULL)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	int	fd;
	int	ret;
	char	*line;
	char	*cpy;

	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		
		ret = get_next_line(fd, &line);
		ft_putendl(line);
		
		ret = get_next_line(fd, &line);
		ft_putendl(line);
		
		ret = get_next_line(fd, &line);
		ft_putendl(line);
		
		ret = get_next_line(fd, &line);
		ft_putendl(line);

		ret = get_next_line(fd, &line);
		ft_putendl(line);
	}
	return (0);
}*/
