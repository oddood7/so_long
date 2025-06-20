/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:32:17 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/12 13:32:22 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_shape(char **map, t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf("Error\nmap must be rectangular\n");
			return (0);
		}
		i++;
	}
	if (i > 22 || len > 43)
	{
		ft_printf("Error\nMap is too big\n");
		return (0);
	}
	data->height = i;
	data->width = len;
	return (1);
}

int	verif_closed(char **map, t_data *data)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(map[0]);
	data->height = len;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == data->height - 1)
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	verif_content(char **map)
{
	int	exit;
	int	player;
	int	i;
	int	j;

	i = 0;
	exit = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	ft_checkexitplayer(exit, player);
	if (exit != 1 || player != 1)
		return (0);
	return (1);
}

int	verif_char(char **map)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				return (ft_printf("Error\nInvalid character in map\n"));
			if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (!(collector(collect)))
		return (0);
	return (1);
}

int	check_format(char *s)
{
	int		len;
	int		i;
	char	*ber;

	ber = ".ber";
	len = ft_strlen(s) - 1;
	i = 3;
	while (i >= 0)
	{
		if (ber[i] != s[len])
			return (0);
		i--;
		len--;
	}
	return (1);
}
