/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/16 20:38:00 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include "42-Libft/libft.h"

void	cub3d_loop(t_map *map)
{
	t_cub3d	cub3d;

	(void)map;
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1000, 1000, "CUB3D WINDOWS!!!");
	key_input(&cub3d);
	mlx_loop(cub3d.mlx);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	map = map_init(map, av[1]);

	if (ac == 2)
	{
		cub3d_loop(map);
	}
	return (0);
}