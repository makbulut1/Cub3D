/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:50:41 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:50:42 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	event_exit(void *tmp)
{
	(void)tmp;
	exit(0);
}

void	event_handler(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, event_up, data);
	mlx_hook(data->mlx_win, 3, 0, event_down, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_hook(data->mlx_win, 17, 0, event_exit, 0);
}
