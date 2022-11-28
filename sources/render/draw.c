/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:50 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:51 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_line(int x1, int y1, t_data *data)
{
	int		dx[2];
	int		steps;
	float	inc[2];
	float	x;
	float	y;

	dx[0] = x1 - data->pos.x * 10;
	dx[1] = y1 - data->pos.y * 10;
	if (abs(dx[0]) > abs(dx[1]))
		steps = abs(dx[0]);
	else
		steps = abs(dx[1]);
	inc[0] = dx[0] / (float)steps;
	inc[1] = dx[1] / (float)steps;
	x = data->pos.x * 10;
	y = data->pos.y * 10;
	dx[0] = -1;
	while (++dx[0] <= steps)
	{
		image_put_pixel(&data->mini_map, x, y, 0xffff00);
		x += inc[0];
		y += inc[1];
	}
}

void	draw_wall(t_data *data, float distance, t_found cord_data, int index)
{
	int		draw;
	float	rate_i;
	int		start;
	int		end;

	draw_line(cord_data.x * 10, cord_data.y * 10, data);
	draw = (5 / distance) * (WIN_HEIGHT * 0.3f);
	rate_i = (float)data->imgs[data->active_img].height / draw;
	start = (WIN_HEIGHT - draw) / 2;
	end = 0;
	if (start < 0)
	{
		draw += start;
		end = -start;
	}
	while (draw-- > end)
		image_put_pixel(&data->screen, index, draw + start,
			image_get_pixel(&data->imgs[data->active_img],
				data->imgs[data->active_img].width * cord_data.rate,
				draw * rate_i));
}
