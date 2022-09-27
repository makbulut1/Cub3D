/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/27 22:20:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include "Libft/libft.h"

void cub3d_loop(t_map map)
{
	t_cub3d cub3d;

	(void)map;
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1000, 1000, "CUB3D WINDOWS!!!");
	key_input(&cub3d);
	mlx_loop(cub3d.mlx);
}

void ft_parse_map(t_map *map)
{
	for (int i = 0; map->map_values[i]; i++)
	{
		if (map->map_values[i] == '\n' && map->map_values[i + 1] == '\0')
			exit(1);
	}
	map->all_map_file = ft_split(map->map_values, '\n');
}

int main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		if (map_init(av[1], &map.map_values))
			return (-1);
		ft_parse_map(&map);
		cub3d_loop(map);
	}
	return (0);
}
