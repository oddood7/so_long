/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:02:22 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/01 20:02:24 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map)
{
	int	fd;

	fd = open(map, O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf("Error\nMap is a directory\n");
		return (-1);
	}
	fd = open(map, O_RDONLY);
	return (fd);
}

void	ft_checkexitplayer(int exit, int player)
{
	if (exit == 0)
		ft_printf("Error\nNo exit\n");
	if (exit > 1)
		ft_printf("Error\nMore than one exit\n");
	if (player == 0)
		ft_printf("Error\nNo player\n");
	if (player > 1)
		ft_printf("Error\nMore than one player");
}

void	init_render(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, (data->width * 60),
			(data->height * 60), "So_long");
	if (data->mlx_win == NULL)
	{
		free (data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, &close_mouse, data);
	mlx_loop(data->mlx_ptr);
}

int	render(t_data *data)
{
	render_map(data);
	render_elements(data);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w)
		render_top(data);
	if (keycode == XK_a)
		render_left(data);
	if (keycode == XK_s)
		render_down(data);
	if (keycode == XK_d)
		render_right(data);
	if (keycode == XK_Escape)
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
	return (0);
}
