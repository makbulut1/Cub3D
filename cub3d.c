/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/29 21:19:31 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h> //silinebilir
#include "Libft/libft.h"
// int mapX = 8, mapY = 8, mapS = 64;

// int map1[] =
// {
// 	1,1,1,1,1,1,1,1,
// 	1,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,0,1,
// 	1,0,0,0,0,0,78,1,
// 	1,0,0,0,0,0,0,1,
// 	1,1,1,1,1,1,1,1,
// };

void ft_put_protect(t_cub3d cub3d, int x, int y, int width)
{
	int x_cp;
	int y_cp;

	x_cp = x;
	y_cp = y;
	while (y != y_cp + width)
	{
		if (x == x_cp + width)
		{
			x -= width;
			y += 1;
		}
		else
		{
			mlx_pixel_put(cub3d.mlx, cub3d.win, x, y, 0x0FAE1);
			x++;
		}
	}
}

void cub3d_loop(t_map map)
{
	t_cub3d cub3d;

	(void)map;
	cub3d.x = 512;
	cub3d.y = 390;
	cub3d.width = 100;
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1024, 780, "CUB3D WINDOWS!!!");
	ft_put_protect(cub3d, cub3d.x, cub3d.y, cub3d.width);
	key_input(&cub3d);
	mlx_loop(cub3d.mlx);
}

int main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		if (map_init(av[1], &map.map_values))
			return (-1);
		cub3d_loop(map);
	}
	return (0);
}
