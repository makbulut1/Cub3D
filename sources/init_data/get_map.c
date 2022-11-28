/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:15 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:17 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	allocate_map(t_data *data, char **line)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = -1;
	while (line[++y])
	{
		x = 0;
		while (line[y][x])
			x++;
		if (data->x_size < x)
			data->x_size = x;
	}
	data->y_size = y;
	data->map = (int **)ft_calloc(y, sizeof(int *));
	while (++i < y)
		data->map[i] = (int *) ft_calloc(data->x_size, sizeof(int));
}

void	get_map(t_data *data, char **line)
{
	int	x;
	int	y;
	int	lock;

	y = -1;
	allocate_map(data, line);
	while (++y < data->y_size)
	{
		x = -1;
		lock = 0;
		while (++x < data->x_size)
		{
			if (!lock && (line[y][x] == '\0' || line[y][x] == '\n'))
				lock = 1;
			if (lock)
				data->map[y][x] = ' ';
			else
				data->map[y][x] = line[y][x];
		}
	}
}
