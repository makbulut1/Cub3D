/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:36 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:37 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_position(t_map *map)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = -1;
	while (map->data[++i])
	{
		k = -1;
		while (map->data[i][++k])
		{
			if (ft_strchr("WESN", map->data[i][k]))
			{
				while (map->data[i][k] != "ENWS"[t])
					t++;
				map->ang = t * 90;
				map->data[i][k] = '0';
				map->y = i;
				map->x = k;
				return ;
			}
		}
	}
}
