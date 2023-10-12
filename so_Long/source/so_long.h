/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:06:08 by fgunay            #+#    #+#             */
/*   Updated: 2023/09/26 15:06:13 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PL_FT "./images/zabita.xpm"
# define FOOD "./images/simitci.xpm"
# define EXIT "./images/exit.xpm"
# define BACKG "./images/background.xpm"
# define WALL "./images/wall.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*player_f;
	void	*exit;
	void	*wall;
	void	*food;
	void	*background;
	int		imgx;
	int		imgy;
	int		position_x;
	int		position_y;
	int		ply_x;
	int		ply_y;
	int		map_x;
	int		map_y;
	char	*map1;
	char	**map2;
	char	**tmp_map2;
	int		food_count;
	int		tmp_food_count;
	int		exit_count;
	int		player_count;
	int		valid_e;
	int		move_count;
	char	*move_count_screen;
}			t_data;

void	ber_check(char *map_name, t_data *data);
int		key_event(int keycode, t_data *data);
void	make_map(t_data *data, char *map);
void	ft_error(char *msg, t_data *data);
void	map_check(t_data *data);
void	count_check(t_data *data);
void	rectangular_check(t_data *data);
void	wall_check(t_data *data);
void	wall_leftright_check(t_data *data);
void	validmap_check(t_data *data, int x, int y);
void	path_check(t_data *data);
void	init_image(t_data *data);
void	put_image(t_data *data);
void	put_image_player(t_data *data, int x, int y);
void	score(t_data *data);
void	init_xy(int *x, int *y);
void	xy_operation(int *x, int *y, t_data *data);
void	render_after_move(t_data *data);
void	check_up(int key, t_data *data);
void	check_down(int key, t_data *data);
void	check_right(int key, t_data *data);
void	check_left(int key, t_data *data);
int		check_movement(t_data *data, int x, int y);
int		close_window(t_data *data);
void	free_map(t_data *data);
void	ft_if_else(t_data *data, int i, int j);
void	newline_check(t_data *data);

#endif
