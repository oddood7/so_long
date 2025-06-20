/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:24:11 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/12 13:24:14 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collect(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	render_top(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && data->map[y - 1][x] != '1')
			{
				if (data->map[y - 1][x] == 'E' && !check_collect(data->map))
					return ;
				if (data->map[y - 1][x] == 'E' && check_collect(data->map))
					win_end(data);
				data->map[y][x] = '0';
				data->map[y - 1][x] = 'P';
				data->step_count++;
				ft_printf("steps count : %d\n", data->step_count);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	render_down(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && data->map[y + 1][x] != '1')
			{
				if (data->map[y + 1][x] == 'E' && !check_collect(data->map))
					return ;
				if (data->map[y + 1][x] == 'E' && check_collect(data->map))
					win_end(data);
				data->map[y][x] = '0';
				data->map[y + 1][x] = 'P';
				data->step_count++;
				ft_printf("steps count : %d\n", data->step_count);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	render_left(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && data->map[y][x - 1] != '1')
			{
				if (data->map[y][x - 1] == 'E' && !check_collect(data->map))
					return ;
				if (data->map[y][x - 1] == 'E' && check_collect(data->map))
					win_end(data);
				data->map[y][x] = '0';
				data->map[y][x - 1] = 'P';
				data->step_count++;
				ft_printf("steps count : %d\n", data->step_count);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	render_right(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && data->map[y][x + 1] != '1')
			{
				if (data->map[y][x + 1] == 'E' && !check_collect(data->map))
					return ;
				if (data->map[y][x + 1] == 'E' && check_collect(data->map))
					win_end(data);
				data->map[y][x] = '0';
				data->map[y][x + 1] = 'P';
				data->step_count++;
				ft_printf("steps count : %d\n", data->step_count);
				return ;
			}
			x++;
		}
		y++;
	}
}
