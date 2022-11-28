/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:55 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:56 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_screen(t_data *data)
{
	int		x;
	int		y;
	int		middle;

	middle = data->screen.height / 2;
	y = -1;
	while (++y < middle)
	{
		x = -1;
		while (++x < data->screen.width)
			image_put_pixel(&data->screen, x, y, data->ceil_color);
	}
	while (++y < data->screen.height)
	{
		x = -1;
		while (++x < data->screen.width)
			image_put_pixel(&data->screen, x, y, data->floor_color);
	}
}
