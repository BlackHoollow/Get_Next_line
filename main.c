/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:42:55 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/01 16:53:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	argc = argc + 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d : %s\n", ret, line);
		ft_strdel(&line);
	}
	return (0);
}
