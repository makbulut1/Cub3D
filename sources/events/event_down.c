/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:50:35 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:50:36 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	event_down(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 0;
	else if (key == 1)
		data->keys.s = 0;
	else if (key == 0)
		data->keys.a = 0;
	else if (key == 2)
		data->keys.d = 0;
	else if (key == 123)
		data->keys.left = 0;
	else if (key == 124)
		data->keys.right = 0;
	return (0);
}
