/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:00 by enpardo-          #+#    #+#             */
/*   Updated: 2025/03/02 20:14:19 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (0);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*copy;

	copy = str;
	while (n > 0)
	{
		*copy = (unsigned char)c;
		copy++;
		n--;
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*pt;
	size_t		total_size;
	static int	j;

	j++;
	if (j == 2)
		return (NULL);
	if (nmemb == 2147483647 || size == 2147483647)
		return (NULL);
	else
		total_size = nmemb * size;
	pt = malloc(nmemb * size);
	if (!pt)
		return (NULL);
	if (total_size > 0)
		ft_memset(pt, 0, total_size);
	return (pt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)ft_calloc(len + 1, 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)ft_calloc(ft_strlen(s1) + 1, 1);
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}
