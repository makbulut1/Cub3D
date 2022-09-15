/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/15 22:32:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include "42-Libft/libft.h"

void	cub3d_loop(void)
{
	t_cub3d	cub3d;
	t_map	*map;

	map = NULL;
	if (map && map->map_values)
		ft_putstr_fd(map->map_values, 1);
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1000, 1000, "CUB3D WINDOWS");
	mlx_loop(cub3d.mlx);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = map_init(map, av[1]);
	if (ac == 2)
	{
		cub3d_loop();
	}
	return (0);
}
