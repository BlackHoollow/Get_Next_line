/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/16 13:51:58 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int const fd)//, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*rest;
	char		*cpy_buff;
	int			i;
	static int	si;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	buff[ret] = '\0';
	cpy_buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (si > 0)
		cpy_buff = ft_strcpy(cpy_buff, rest);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			cpy_buff = ft_strncat(cpy_buff, buff, i);
			rest = ft_strsub(buff, i + 1, (BUFF_SIZE - i)); 
		}
		else
		{
			cpy_buff = ft_strcpy(cpy_buff, buff);
			i++;
		}
	}	
	ft_putstr(cpy_buff);
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd);
	}
	return (0);
}	
