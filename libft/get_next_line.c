/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:01:21 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/01 20:01:25 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	int		len;
	int		i;
	char	*dest;

	i = 0;
	len = 0;
	if (!str[i])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	dest = ft_calloc((len + 2), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_new_line(int fd, char *str)
{
	int		rd;
	char	*buff;

	rd = 1;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (rd != 0 && !has_newline(buff))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*left_line(char *str)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i++;
	while (str[i + j])
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	str = get_new_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = left_line(str);
	return (line);
}
