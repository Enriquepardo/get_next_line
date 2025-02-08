/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:09:44 by enpardo-          #+#    #+#             */
/*   Updated: 2025/02/08 21:47:01 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

static char *read_from_fd(int fd, char *buffer, char *remainder)
{
    ssize_t bytes_read;
    char *temp;

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (NULL);
        buffer[bytes_read] = '\0';
        temp = remainder;
        remainder = ft_strjoin(temp, buffer);
        free(temp);
        if (ft_strchr(remainder, '\n'))
            break;
    }
    return (remainder);
}

static char *extract_line(char **remainder)
{
    char *line;
    char *newline_pos;
    char *temp;

    newline_pos = ft_strchr(*remainder, '\n');
    if (newline_pos)
    {
        line = ft_substr(*remainder, 0, newline_pos - *remainder + 1);
        temp = *remainder;
        *remainder = ft_strdup(newline_pos + 1);
        free(temp);
    }
    else
    {
        line = ft_strdup(*remainder);
        free(*remainder);
        *remainder = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    remainder = read_from_fd(fd, buffer, remainder);
    free(buffer);
    if (!remainder)
        return (NULL);
    line = extract_line(&remainder);
    return (line);
}

// main

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}