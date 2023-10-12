/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:06:29 by fgunay            #+#    #+#             */
/*   Updated: 2023/09/26 15:06:32 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map2[i])
	{
		len++;
		i++;
	}
	data->map_y = len;
	i = 0;
	while (data->map2[0][i] && data->map2[len - 1][i])
	{
		if (data->map2[0][i] != '1' || data->map2[len - 1][i] != '1')
			ft_error("Error\nThe walls are not closed.\n", data);
		i++;
	}
	wall_leftright_check(data);
}

void	wall_leftright_check(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = data->map_x;
	while (i < data->map_y)
	{
		if (data->map2[i][0] != '1' || data->map2[i][len - 1] != '1')
			ft_error("Error\nThe walls are not closed.", data);
		i++;
	}
	data->tmp_food_count = data->food_count;
}

void	validmap_check(t_data *data, int x, int y)
{
	char	*p;

	p = &data->tmp_map2[y][x];
	if (*p == 'E')
		data->valid_e = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			data->tmp_food_count--;
		*p = '.';
		if (data->tmp_map2[y][x + 1] != '1' &&
			data->tmp_map2[y][x + 1] != '.')
			validmap_check(data, x + 1, y);
		if (data->tmp_map2[y][x - 1] != '1' &&
			data->tmp_map2[y][x - 1] != '.')
			validmap_check(data, x - 1, y);
		if (data->tmp_map2[y - 1][x] != '1' &&
			data->tmp_map2[y - 1][x] != '.')
			validmap_check(data, x, y - 1);
		if (data->tmp_map2[y + 1][x] != '1' &&
			data->tmp_map2[y + 1][x] != '.')
			validmap_check(data, x, y + 1);
	}
}

void	path_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->tmp_map2[i])
	{
		free(data->tmp_map2[i]);
		i++;
	}
	free(data->tmp_map2);
	if (data->tmp_food_count != 0 || data->valid_e != 1)
		ft_error("Error\nThere is no valid way out.", data);
}
