/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/13 23:00:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	cub3d_loop(void)
{
	t_cub3d	cub3d;

	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1000, 1000, "Windows");
	mlx_loop(cub3d.mlx);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
		cub3d_loop();
	return (0);
}
