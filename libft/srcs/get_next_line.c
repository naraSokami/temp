/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:08:49 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/28 17:17:09 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *line, char *buff, int size)
{
	char	*joined;
	int		line_size;
	int		i;

	if (!buff || size < 1)
		return (line);
	line_size = ft_strlen_end(line);
	joined = malloc(sizeof(char) * (line_size + size + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (line && i < line_size)
	{
		joined[i] = line[i];
		i++;
	}
	while (i < line_size + size)
	{
		joined[i] = buff[i - line_size];
		i++;
	}
	joined[i] = 0;
	if (line)
		free(line);
	return (joined);
}

void	ft_memmove(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_get_line(int fd, char buff[BUFFER_SIZE + 1])
{
	char			*line;
	int				c_read;
	int				size;

	line = NULL;
	size = ft_strlen_end(buff);
	if (size > 0)
	{
		line = ft_strndup(buff, size);
		if (!line)
			return (NULL);
		ft_memmove(buff, buff + size, BUFFER_SIZE - size);
	}
	c_read = 1;
	while (c_read > 0 && (!line || line[ft_strlen_end(line) - 1] != '\n'))
	{
		c_read = read(fd, buff, BUFFER_SIZE);
		if (c_read == -1)
			return (free(line), NULL);
		buff[c_read] = 0;
		size = ft_strlen_end(buff);
		line = ft_strnjoin(line, buff, size);
		ft_memmove(buff, buff + size, BUFFER_SIZE - size);
	}
	return (line);
}

void	ft_bzero(char *str, size_t size)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || read(fd, buff, 0) == -1)
	{
		ft_bzero(buff, BUFFER_SIZE);
		return (NULL);
	}
	line = ft_get_line(fd, buff);
	return (line);
}
