/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/15 20:33:05 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_boucle(char *buff, char *cpy_buff, int fd)
{
	char	*tmp;
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
}*/

int		get_next_line(int const fd)//, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*rest;
	char		*cpy_buff;
	int			i;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	cpy_buff = ft_strcpy(cpy_buff, rest);
	while (buff[i] != '\n')
		i++;
	cpy_buff = ft_strncat(cpy_buff, buff, i + 1);
	rest = ft_strsub(buff, i + 1, (ft_strlen(buff) - i));
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
