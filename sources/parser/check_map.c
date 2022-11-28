/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:00 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:02 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_map(t_map *map, char *s, char *s2)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (!ft_strchr(s, map->data[i][j]))
				return (-1);
			if (ft_strchr(s2, map->data[i][j]))
				k++;
			j++;
		}
		i++;
	}
	if (1 != k)
		return (-1);
	i = 0;
	return (0);
}
