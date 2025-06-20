/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:01:29 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/13 14:10:51 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_newline(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] == '\n')
		return (ft_printf("Error\nNewline as first char in map"));
	while (s[j])
		j++;
	if (s[j - 1] == '\n')
		return (ft_printf("Error\nNewline at end of map"));
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (ft_printf("Error\nConsecutive newlines"));
		i++;
	}
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s);
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_tablen(char **tab)
{
	size_t	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

char	**ft_tabdup(char **tab)
{
	char	**dest;
	size_t	y;

	y = 0;
	dest = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (y < ft_tablen(tab))
	{
		dest[y] = ft_strdup(tab[y]);
		y++;
	}
	dest[y] = NULL;
	return (dest);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
