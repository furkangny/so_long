/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:37:38 by fgunay            #+#    #+#             */
/*   Updated: 2023/09/26 15:37:41 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_data *data)
{
	data->player_f = mlx_xpm_file_to_image(data->mlx, PL_FT, &data->imgx,
			&data->imgy);
	data->food = mlx_xpm_file_to_image(data->mlx, FOOD, &data->imgx,
			&data->imgy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->imgx,
			&data->imgy);
	data->background = mlx_xpm_file_to_image(data->mlx, BACKG, &data->imgx,
			&data->imgy);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->imgx,
			&data->imgy);
	data->window = mlx_new_window(data->mlx, data->map_x * 64, data->map_y * 64,
			"so_long");
	put_image(data);
}

void	put_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y * 64)
	{
		if (data->map2[y / 64][x / 64] != '1' && data->map2[y / 64][x
			/ 64] != '0')
			mlx_put_image_to_window(data->mlx, data->window, data->background,
				x, y);
		if (data->map2[y / 64][x / 64] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
		else if (data->map2[y / 64][x / 64] == '0')
			mlx_put_image_to_window(data->mlx, data->window, data->background,
				x, y);
		else if (data->map2[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
		else if (data->map2[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(data->mlx, data->window, data->food, x, y);
		else if (data->map2[y / 64][x / 64] == 'P')
			put_image_player(data, x, y);
		xy_operation(&x, &y, data);
	}
	score(data);
}

void	put_image_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->player_f, x, y);
}

void	score(t_data *data)
{
	data->move_count_screen = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->window, 30, 30, 0xFFFFFF, "Move: ");
	mlx_string_put(data->mlx, data->window, 65, 30, 0xFFFFFF,
		data->move_count_screen);
	free(data->move_count_screen);
}

void	ft_if_else(t_data *data, int i, int j)
{
	data->player_count++;
	data->ply_x = j;
	data->ply_y = i;
}
