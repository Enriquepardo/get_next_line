/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:09:44 by enpardo-          #+#    #+#             */
/*   Updated: 2025/02/22 20:50:20 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *buffer, int *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == -1)
		return (NULL);
	buffer[*bytes_read] = '\0';
	return (buffer);
}

static char	*allocate_storage(char *storage)
{
	if (!storage)
	{
		storage = ft_strdup("");
		if (!storage)
			return (NULL);
	}
	return (storage);
}

static char	*process_reading(int fd, char *storage, char *buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		if (!read_buffer(fd, buffer, &bytes_read))
			return (NULL);
		temp = ft_strjoin(storage, buffer);
		if (!temp)
			return (NULL);
		free(storage);
		storage = temp;
	}
	return (storage);
}

static char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	char	*new_storage;

	storage = allocate_storage(storage);
	if (!storage)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	new_storage = process_reading(fd, storage, buffer);
	free(buffer);
	if (!new_storage)
		return (free(storage), NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*temp;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage || !*storage)
		return (free(storage), storage = NULL, NULL);
	len = 0;
	while (storage[len] && storage[len] != '\n')
		len++;
	line = ft_substr(storage, 0, len + (storage[len] == '\n'));
	temp = ft_strdup(storage + len + (storage[len] == '\n'));
	if (!line || !temp)
	{
		free(line);
		free(temp);
		return (NULL);
	}
	free(storage);
	storage = temp;
	return (line);
}
