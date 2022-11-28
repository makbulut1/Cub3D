/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:41 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 21:19:45 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	*init_map(int fd)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (-1 == get_param(map, fd, NULL) || -1 == map->c.f || -1 == map->f.f)
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		clear_map(map);
		return (NULL);
	}
	if (-1 == get_map_fd(map, fd) || -1 == check_map(map, "01NSEW ", "NWES")
		|| check_wall(map, '0') || check_wall(map, 'N')
		|| check_wall(map, 'S') || check_wall(map, 'W') || check_wall(map, 'E'))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		clear_map(map);
		return (NULL);
	}
	return (map);
}
