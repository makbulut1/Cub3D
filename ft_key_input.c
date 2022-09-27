/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:12:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/27 22:20:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "Libft/libft.h"
#include "mlx/mlx.h"

int	close_screen(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit(1);
}

int	key_hook(int key)
{
	if (key == 53)
	{
		ft_putendl_fd("Game Exited", 1);
		exit(1);
	}
	return (0);
}

void	key_input(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 1L << 17, close_screen, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_hook, cub3d);
}
