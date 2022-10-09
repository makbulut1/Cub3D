/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/10/05 22:05:59 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h> //silinebilir
#include "Libft/libft.h"
#include "map_parse/map_parse.h"

int mapX = 8, mapY = 8, mapS = 64;

float pdx = 3, pdy = 0, pa;

int map1[] =
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1};


int creat_rgb(int red, int green, int blue)
{
	return (red * 65536 + green * 256 + blue);
}

int close_screen(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit(1);
}

int	key_hook(int key, t_cub3d *cub3d)
{
	(void)cub3d;
	if (key == 53)
	{
		ft_putendl_fd("Game Exited", 1);
		exit(1);
	}
	else if (key == A || key == 123)
	{
        pa -= 0.1; if (pa < 0){pa += 2 * PI;} pdx = cos(pa) * 5; pdy = sin(pa) * 5;
	}
	else if (key == S || key == 125)
	{
        cub3d->y -= pdy;
        cub3d->x -= pdx;
	}
	else if (key == D || key == 124)
	{
        pa += 0.1; if (pa > PI * 2){pa -= 2 * PI;} pdx = cos(pa) * 5; pdy = sin(pa) * 5;
	}
	else if (key == W || key == 126)
	{
        cub3d->y += pdy;
        cub3d->x += pdx;
	}
	ft_map_render(*cub3d);
	return (0);
}

void key_input(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 1L << 17, close_screen, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_hook, cub3d);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void ft_player_direction(float slope, float x1, float y1, float degree, t_cub3d cub3d, t_data *img)
{
	float i = 0;
	while (x1 > -5 && x1 < 512)
	{
		if (degree < 90 || degree > 270)
		{
			if ((x1 > 61 && x1 < 451) && (y1 + (slope * i) > 61 && y1 + (slope * i) < 451))
				my_mlx_pixel_put(img, x1 + (cub3d.width / 2), y1 + (cub3d.width / 2) + (slope * i), cub3d.color);
			x1 += 0.055;
		}
		else
		{
			if ((x1 > 61 && x1 < 451) && (y1 - (slope * i) > 61 && y1 - (slope * i) < 451))
				my_mlx_pixel_put(img, x1 + (cub3d.width / 2), y1 + (cub3d.width / 2) - (slope * i), cub3d.color);
			x1 -= 0.055;
		}
		i += 0.055;
	}
}

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

void ft_protect(t_cub3d cub3d, int x, int y, int width, int color, t_data *img)
{
	int x_cp;
	int y_cp;
	static int a;
	static int b;

	static int i = 1;
	if (color == 0xfffffff /* && b != y */) // Duvar konumlarının kordinatları alınmaya çalışılıyor.
		// printf("\x1b[33m%d - eski (%d, %d)\n\x1b[0m\x1b[31m%d - yeni(%d, %d)\n\x1b[0m",i, x, y, i, x + 65, y + 65);//	printf("(%d, %d) (%d, %d)\n", (a - x), y , x,  -(b - y));
	i++;
	a = x;
	b = y;
	x_cp = x;
	(void)cub3d;
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
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
	}
	// if (color == 0xfffffff /* && b != y */) // Duvar konumlarının kordinatları alınmaya çalışılıyor.
	// 	printf("eski (%d,-%d)\n yeni(%d,-%d)\n", x, y, x + 65, y + 65);
}

void ft_protect_player(t_cub3d cub3d, int x, int y, int width, int color, t_data *img)
{
	int x_cp;
	int y_cp;
	static int a;
	static int b;

	a = x;
	b = y;
	x_cp = x;
	(void)cub3d;
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
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
	}
}

void ft_put_map(t_cub3d cub3d, t_data *img)
{
	int x = 0, y = 0, xo = 0, yo = 0;
	int i = -1, j = 0;
	while (i++ < mapS)
	{
		if (x == mapX * 65)
		{
			j++;
			if (j == 8)
				break;
			x = 0;
			y += 64;
			y++;
			yo++;
		}
		if (map1[i] == 1)
		{
			cub3d.color = 0xFFFFFFF;
		}
		else if (map1[i] == 32)
			cub3d.color = 0x00000000;
		else
			cub3d.color = 0x0808080;
		ft_protect(cub3d, x, y, 64, cub3d.color, img);
		cub3d.color = 0;
		x += 64;
		x++;
		xo++;
	}
	cub3d.color = creat_rgb(29, 151, 242);
	ft_protect_player(cub3d, cub3d.x, cub3d.y, cub3d.width, cub3d.color, img);
	ft_player_direction(tanf(pa), cub3d.x, cub3d.y, 57.2957795 * pa, cub3d, img);
}

void ft_map_render(t_cub3d cub3d)
{
	t_data img;

	mlx_clear_window(cub3d.mlx, cub3d.win);
	img.img = mlx_new_image(cub3d.mlx, 520, 520);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_put_map(cub3d, &img);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, img.img, 0, 0);
}

void cub3d_loop(t_map a)
{
	t_cub3d cub3d;

	(void)a; // map olarak düzeltilecek bu değişken
	cub3d.x = 72;
	cub3d.y = 192;
	cub3d.width = 8;
	cub3d.color = creat_rgb(29, 151, 242);
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1024, 512, "CUB3D WINDOWS!!!");
	key_input(&cub3d);
	ft_map_render(cub3d);
	mlx_loop(cub3d.mlx);
}

int main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		map_control(av[1]);
		if (map_init(av[1], &map.map_values))
			return (-1);
		cub3d_loop(map);
	}
	return (0);
}
