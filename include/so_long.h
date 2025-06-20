/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:06:49 by rmarecar          #+#    #+#             */
/*   Updated: 2023/07/01 19:49:19 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

typedef struct img_s
{
	int		img_height;
	int		img_width;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_item;
	void	*img_exit;
}			t_img;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		height;
	int		width;
	int		step_count;
	t_img	img;
}	t_data;

/*char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(size_t count, size_t size);
char	**ft_split(const char *s, char sep);
char	*ft_strdup(const char *s);
size_t     ft_tablen(char **tab);
char    **ft_tabdup(char **tab);
int     ft_check_newline(char *s);*/
				/*MAP VERIF AND PARSE*/
char	**map_to_tab(int fd);
int		map_verif(t_data *data);
void	free_tab(char **tab);
void	map_way(char **map, int x, int y, int j);
int		map_way2(char **map);
int		valid_map(char **map, t_data *data);
int		check_format(char *s);
int		verif_char(char **map);
int		verif_content(char **map);
int		verif_closed(char **map, t_data *data);
int		verif_shape(char **map, t_data *data);
void	ft_checkexitplayer(int exit, int player);
int		collector(int collect);
int		open_map(char *map);

				/*RENDER MAP*/
void	render_map(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
void	render_elements(t_data *data);
void	set_img(t_data *data);
int		render(t_data *data);
void	init_render(t_data *data);
				/*RENDER KEYPRESS*/
int		key_press(int keycode, t_data *data);
int		check_collect(char **map);
void	win_end(t_data *data);
int		close_mouse(t_data *data);
				/*RENDER MOVES*/
void	render_top(t_data *data);
void	render_down(t_data *data);
void	render_left(t_data *data);
void	render_right(t_data *data);
void	change_exit(char **map);

#endif
