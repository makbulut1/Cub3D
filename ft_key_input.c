/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:12:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/10/03 16:41:49 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "Libft/libft.h"
#include "mlx/mlx.h"
#include <stdio.h> //silinebilir
#include <math.h>

// int	close_screen(t_cub3d *cub3d)
// {
// 	mlx_destroy_window(cub3d->mlx, cub3d->win);
// 	exit(1);
// }

// int	key_hook(int key, t_cub3d *cub3d)
// {
// 	(void)cub3d;
// 	if (key == 53)
// 	{
// 		ft_putendl_fd("Game Exited", 1);
// 		exit(1);
// 	}
// 	else if (key == A || key == 123)
// 	{
//         pa -= 0.1; if (pa < 0){pa += 2 * PI;} pdx = cos(pa) * 5; pdy = sin(pa) * 5;
// 	}
// 	else if (key == S || key == 125)
// 	{
//         cub3d->y -= pdy;
//         cub3d->x -= pdx;
// 	}
// 	else if (key == D || key == 124)
// 	{
//         pa += 0.1; if (pa > PI * 2){pa -= 2 * PI;} pdx = cos(pa) * 5; pdy = sin(pa) * 5;
// 	}
// 	else if (key == W || key == 126)
// 	{
//         cub3d->y += pdy;
//         cub3d->x += pdx;
// 	}
// 	ft_map_render(*cub3d);
// 	return (0);
// }

// void	key_input(t_cub3d *cub3d)
// {
// 	mlx_hook(cub3d->win, 17, 1L << 17, close_screen, cub3d);
// 	mlx_hook(cub3d->win, 2, 1L << 0, key_hook, cub3d);
// }

