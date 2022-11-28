/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/11/23 21:31:55 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	map_render(t_data *data)
{
	int	i;
	int	j;
	int	ix;
	int	iy;

	i = -1;
	while (++i < 100 && data->map_in_data->data[i])
	{
		j = -1;
		while (++j < 100 && data->map_in_data->data[i][j])
		{
			if (data->map_in_data->data[i][j] == '1')
			{
				ix = 0;
				while (++ix < 10)
				{
					iy = 0;
					while (++iy < 10)
						image_put_pixel(&data->mini_map, (j * 10) + ix, \
							(i * 10) + iy, 0xff0000);
				}
			}
		}
	}
	minimap_render(data);
}

void	minimap_render(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 200)
	{
		j = -1;
		while (++j < 200)
		{
			if (data->pos.x * 10 + i - 100 >= 0 && \
				data->pos.y * 10 + j - 100 >= 0)
				image_put_pixel(&data->part_of_map, j, i,
					image_get_pixel(&data->mini_map, data->pos.x * 10 + \
						i - 100, data->pos.y * 10 + j - 100));
		}
	}
}

void	start_game(t_data *data, t_map *map)
{
	data->pos.x = map->x + 0.5f;
	data->pos.y = map->y + 0.5f;
	data->look = (map->ang + 180) * ANLE_TO_RADIAN;
	render(data);
}

void	init_image(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen.width = WIN_WIDTH;
	data->screen.height = WIN_HEIGHT;
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
	data->mini_map.img = mlx_new_image(data->mlx, (data->x_size + 1) * 10, \
	(data->y_size + 1) * 10);
	data->mini_map.width = (data->x_size + 1) * 10;
	data->mini_map.height = (data->y_size + 1) * 10;
	data->mini_map.addr = mlx_get_data_addr(data->mini_map.img, \
		&data->mini_map.bbp, &data->mini_map.line_len, &data->mini_map.endian);
	data->part_of_map.img = mlx_new_image(data->mlx, 200, 200);
	data->part_of_map.width = 200;
	data->part_of_map.height = 200;
	data->part_of_map.addr = mlx_get_data_addr(data->part_of_map.img, \
		&data->part_of_map.bbp, &data->part_of_map.line_len, \
			&data->part_of_map.endian);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map;

	if (argc != 2)
		return (1);
	map = create_map(argv[1]);
	if (map == NULL)
		return (1);
	data.map_in_data = map;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "...");
	get_data(&data, map);
	init_image(&data);
	start_game(&data, map);
	event_handler(&data);
	mlx_loop(data.mlx);
	return (0);
}
