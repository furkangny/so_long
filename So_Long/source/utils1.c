/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:06:21 by fgunay            #+#    #+#             */
/*   Updated: 2023/09/26 15:06:22 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	newline_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->map1[i])
	{
		if (i == 0 && data->map1[i] == '\n')
			ft_error("Error\nFirst line is empty.", data);
		if (data->map1[i] == '\n' && data->map1[i + 1] == '\n')
			ft_error("Error\nCheck the gaps in the map", data);
		i++;
	}
}

void	ber_check(char *map_name, t_data *data)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e' || map_name[len
			- 3] != 'b' || map_name[len - 4] != '.' || len <= 9)
		ft_error("<<extension must end with .ber>>", data);
}

void	make_map(t_data *data, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nfile could not be opened", data);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("Error\nFile is empty!", data);
	while (buff)
	{
		data->map1 = ft_strjoin(data->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}

void	map_check(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'C')
				data->food_count++;
			else if (data->map2[i][j] == 'E')
				data->exit_count++;
			else if (data->map2[i][j] == 'P')
				ft_if_else(data, i, j);
			else if (data->map2[i][j] != '0' && data->map2[i][j] != '1')
				ft_error("Error\nThe map should contain only 10PEC.\n", data);
			j++;
		}
		i++;
	}
	newline_check(data);
	count_check(data);
}

void	rectangular_check(t_data *data)
{
	int	line_length1;
	int	line_length2;
	int	i;

	i = 0;
	line_length1 = ft_strlen(data->map2[0]);
	data->map_x = line_length1;
	while (data->map2[i])
	{
		line_length2 = ft_strlen(data->map2[i]);
		if (line_length2 != line_length1)
			ft_error("Error\nThe map is not rectangular.", data);
		i++;
	}
}
