/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:12:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/29 21:18:09 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "Libft/libft.h"
#include "mlx/mlx.h"
#include <stdio.h> //silinebilir
int	close_screen(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit(1);
}

int	key_hook(int key, t_cub3d *cub3d)
{
	if (key == 53)
	{
		ft_putendl_fd("Game Exited", 1);
		exit(1);
	}
	else if (key == 0)
	{
		cub3d->x -= cub3d->width;
		mlx_clear_window(cub3d->mlx, cub3d->win);
		ft_put_protect(*cub3d, cub3d->x, cub3d->y, cub3d->width);
	}
	else if (key == 1)
	{
		cub3d->y += cub3d->width;
		mlx_clear_window(cub3d->mlx, cub3d->win);
		ft_put_protect(*cub3d, cub3d->x, cub3d->y, cub3d->width);
	}
	else if (key == 2)
	{
		cub3d->x += cub3d->width;
		mlx_clear_window(cub3d->mlx, cub3d->win);
		ft_put_protect(*cub3d, cub3d->x, cub3d->y, cub3d->width);
	}
	else if (key == 13)
	{
		cub3d->y -= cub3d->width;
		mlx_clear_window(cub3d->mlx, cub3d->win);
		ft_put_protect(*cub3d, cub3d->x, cub3d->y, cub3d->width);
	}
	return (0);
}

void	key_input(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 1L << 17, close_screen, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_hook, cub3d);
}
