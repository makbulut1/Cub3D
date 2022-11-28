/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:51:32 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:51:35 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	update(t_data *data)
{
	float		speed;
	float		look_speed;
	t_vector2f	movement;

	speed = 0.1f;
	look_speed = 0.03f;
	movement = (t_vector2f){0, 0};
	movement.x += cosf(data->look) * speed
		* (data->keys.w - data->keys.s);
	movement.y += sinf(data->look) * speed
		* (data->keys.w - data->keys.s);
	movement.x += cosf(data->look + (PI / 2)) * speed
		* (data->keys.a - data->keys.d);
	movement.y += sinf(data->look + (PI / 2)) * speed
		* (data->keys.a - data->keys.d);
	if (data->keys.left)
		data->look += look_speed;
	if (data->keys.right)
		data->look -= look_speed;
	move(data, movement);
	render(data);
	return (0);
}
