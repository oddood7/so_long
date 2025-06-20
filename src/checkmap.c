/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:22:31 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/12 13:22:35 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_to_tab(int fd)
{
	char	*s1;
	char	*s2;
	char	**tab;

	s1 = ft_calloc(sizeof(char), 1);
	s2 = "b";
	while (s2)
	{
		s2 = get_next_line(fd);
		if (s2)
			s1 = ft_strjoin(s1, s2);
		free(s2);
	}
	if (ft_check_newline(s1) != 1)
	{
		free(s1);
		return (NULL);
	}
	tab = ft_split(s1, '\n');
	free(s1);
	return (tab);
}

int	map_verif(t_data *data)
{
	int	check;

	check = 0;
	check += verif_closed(data->map, data);
	if (check == 0)
		ft_printf("Error\nMap should be closed\n");
	check += verif_shape(data->map, data);
	check += verif_content(data->map);
	check += verif_char(data->map);
	if (check != 4)
		return (0);
	return (1);
}

void	map_way(char **map, int x, int y, int j)
{
	if (j == 1)
		change_exit(map);
	if (x == 0 && y == 0)
	{
		while (map[y])
		{
			x = 0;
			while (map[y][x] && map[y][x] != 'P')
				x++;
			if (map[y][x] == 'P')
				break ;
			y++;
		}
	}
	map[y][x] = '1';
	if (map[y][x + 1] != '1')
		map_way(map, x + 1, y, j);
	if (map[y][x - 1] != '1')
		map_way(map, x - 1, y, j);
	if (map[y + 1][x] != '1')
		map_way(map, x, y + 1, j);
	if (map[y - 1][x] != '1')
		map_way(map, x, y - 1, j);
}

int	map_way2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(char **map, t_data *data)
{
	char	**check;

	if (!map_verif(data))
		return (0);
	check = ft_tabdup(map);
	map_way(check, 0, 0, 0);
	if (!map_way2(check))
	{
		free_tab(check);
		return (ft_printf("Error\nNo solution"));
	}
	free_tab(check);
	check = ft_tabdup(map);
	map_way(check, 0, 0, 1);
	if (!map_way2(check))
	{
		free_tab(check);
		return (ft_printf("Error\nNo solution"));
	}
	free_tab(check);
	return (1);
}
