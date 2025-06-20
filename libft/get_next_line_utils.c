/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:01:07 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/13 14:10:04 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdint.h>

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	if (size != 0 && nmemb != 0 && (size * nmemb) / size != nmemb)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t		i;
	size_t		j;
	char		*dest;

	i = 0;
	if (!str)
	{
		str = ft_calloc(1, sizeof(char));
		str[0] = '\0';
	}
	dest = ft_calloc((ft_strlen(str) + ft_strlen(buf) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (buf[j])
		dest[i++] = buf[j++];
	free(str);
	dest[i] = '\0';
	return (dest);
}
