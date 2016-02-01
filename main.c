/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:42:55 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/01 16:30:17 by nromptea         ###   ########.fr       */
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
	fd = open("dev/random", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d : %s\n", ret, line);
	}
	return (0);
}
