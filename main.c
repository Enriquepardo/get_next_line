/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:58:41 by enpardo-          #+#    #+#             */
/*   Updated: 2025/02/18 19:54:12 by enpardo-         ###   ########.fr       */
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
		fd = 0; // Leer desde stdin si no se pasa archivo
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error abriendo archivo");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	if (argc > 1)
		close(fd);
	return (0);
}
