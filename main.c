/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:58:41 by enpardo-          #+#    #+#             */
/*   Updated: 2025/03/02 20:02:55 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		fd = 0;
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
	}
	return (0);
}
