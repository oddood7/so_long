/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:21:29 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/12 13:21:35 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_exit(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				map[y][x] = '1';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	close_mouse(t_data *data)
{
	if (data->map != NULL)
		free_tab(data->map);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	mlx_destroy_image(data->mlx_ptr, data->img.img_item);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	win_end(t_data *data)
{
	if (data->map != NULL)
		free_tab(data->map);
	mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	mlx_destroy_image(data->mlx_ptr, data->img.img_item);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	collector(int collect)
{
	if (collect == 0)
	{
		ft_printf("Error\nMap needs at least one collectible\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		return (ft_printf("Error\nneed one map as argument"));
	else
	{	
		if (!check_format(av[1]))
			return (write(1, "Error\nwrong format (not .ber)", 29));
		fd = open_map(av[1]);
		if (fd < 0)
			return (write (1, "Error\ncan't open map", 21));
		data.map = map_to_tab(fd);
		if (!data.map)
			return (0);
		if (valid_map(data.map, &data) == 1)
		{
			data.mlx_ptr = mlx_init();
			set_img(&data);
			init_render(&data);
		}
		if (data.map)
			free_tab(data.map);
	}
	return (0);
}
