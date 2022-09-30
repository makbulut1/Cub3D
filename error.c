/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:43:02 by iyarikan          #+#    #+#             */
/*   Updated: 2022/09/30 00:52:33 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	malloc_err(t_map *map, int fd)
{
	(void)map;
	ft_putstr_fd("Error: Failed To Sort Space With Malloc.\n", 2);
	close(fd);
	exit(1);
}

void	split_err(t_map *map)
{
	ft_putstr_fd("Error\n Split_Error", 2);
	free(map->data->buff);
	exit(1);
}

void	err(t_map *map, char error_code)
{
	if (error_code == '0')
		ft_putstr_fd("Error: File Name Error.\n", 2);
	else if (error_code == '1')
		ft_putstr_fd("Error: File Not Opened.\n", 2);
	else if (error_code == '2')
		ft_putstr_fd("Error : Character Error.\n", 2);
	else if (error_code == '3')
		ft_putstr_fd("Error\n Wall Error", 2);
	free_map(map->data);
	free(map->data->buff);
	exit(1);
}
