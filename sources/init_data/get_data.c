/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:11 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:12 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_data(t_data *data, t_map *map)
{
	if (!data || !map)
		return (1);
	get_args(data, map);
	get_map(data, map->data);
	return (0);
}
