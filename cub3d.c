/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/10/01 15:13:21 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h> //silinebilir
#include "Libft/libft.h"
int mapX = 8, mapY = 8, mapS = 64;

int map1[] =
	{
		1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
};

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
			mlx_pixel_put(cub3d.mlx, cub3d.win, x, y, cub3d.color);
			x++;
		}
	}
}

void ft_protect(t_cub3d cub3d, int x, int y, int width, int color)
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
			mlx_pixel_put(cub3d.mlx, cub3d.win, x, y, color);
			x++;
		}
	}
}

void ft_put_map(t_cub3d cub3d)
{
	int x = 0, y = 0, xo = 0, yo = 0;
	int i = -1;
	// int color = 0;
	while (i++ < mapS)
	{
		if (x == mapX * 65)
		{
			x = 0;
			y += 64;
			y++;
			yo++;
		}
		if (map1[i] == 1)
		{
			cub3d.color = 0x808080;
		}
		else
		{
			cub3d.color = 0xffff;
		}
		ft_protect(cub3d, x, y, 64, cub3d.color);
		cub3d.color = 0;
		x+= 64;
		x++;
		xo++;
	}
}

void ft_map_render(t_cub3d cub3d)
{
	mlx_clear_window(cub3d.mlx, cub3d.win);
	ft_put_map(cub3d);
	
	// ft_put_protect(cub3d, cub3d.x, cub3d.y, cub3d.width);
}

void cub3d_loop(t_map a)
{
	t_cub3d cub3d;

	(void)a; //map olarak düzeltilecek bu değişken
	cub3d.x = 72;
	cub3d.y = 192;
	cub3d.width = 8;
	cub3d.color = 0xE03C00;
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 512, 512, "CUB3D WINDOWS!!!");
	key_input(&cub3d);
	ft_map_render(cub3d);
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
