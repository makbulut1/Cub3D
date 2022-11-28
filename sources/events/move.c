/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:51:27 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:51:28 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	collision_detect(t_data *data, t_vector2f pos)
{
	float	size;

	size = 0.2f;
	return (data->map[(int)(pos.y + size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x - size)] != '1'
		&& data->map[(int)(pos.y + size)][(int)(pos.x - size)] != '1');
}

void	move(t_data *data, t_vector2f move)
{
	if (collision_detect(data,
			(t_vector2f){data->pos.x + move.x, data->pos.y}))
		data->pos.x += move.x;
	if (collision_detect(data,
			(t_vector2f){data->pos.x, data->pos.y + move.y}))
		data->pos.y += move.y;
}
