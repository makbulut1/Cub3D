/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:45:31 by iyarikan          #+#    #+#             */
/*   Updated: 2022/09/30 16:42:02 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_col_row(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->data->y = 0;
	while (map->data->map[i++])
		map->data->y++;
	i = 0;
	map->data->x = 0;
	while (map->data->map[0][i++])
		map->data->x++;
	i = 1;
	while (i < map->data->y)
	{
		j = ft_strlen(map->data->map[i]);
		if (j != map->data->x)
			err(map, '3');
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data->map[i])
	{
		j = 0;
		while (map->data->map[i][j])
		{
			if (i == 0 || i == map->data->y - 1)
			{
				if (map->data->map[i][j] != '1')
					err(map, '1');
			}
			else if (j == 0 || j == map->data->x - 1)
				if (map->data->map[i][j] != '1')
					err(map, '1');
			j++;
		}
		i++;
	}
}

void	map_control(t_map *map, char *av)
{
	int	fd;
	int	i;
	t_data	*data;

	//data = &((t_data){0});
	if (cub_control(av))
		err(map, '0');
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err(map, '1');
	data = malloc(sizeof(t_data) * 999);//
	map->data = data;//
	map->data->buff = malloc(sizeof(char) *999);
	if (!map->data->buff)
		malloc_err(map, fd);
	i = read(fd, map->data->buff, 998);
	map->data->buff[998] = '\0';
	close(fd);
	map->data->map = ft_split(map->data->buff, '\n');
	if (!map->data->map)
		split_err(map);
	//check_chars(map);
	line_add(map->data);
	//check_col_row(map);
	//check_walls(map);
	ft_putendl_fd(map->data->no, 1);
	ft_putendl_fd(map->data->so, 1);
	ft_putendl_fd(map->data->we, 1);
	ft_putendl_fd(map->data->ea, 1);
	ft_putendl_fd(map->data->f, 1);
	ft_putendl_fd(map->data->c, 1);
	//i = -1;
//	while(map->data->new_map[++i])
		ft_putendl_fd(map->data->new_map, 1);
	//line_count();
}
