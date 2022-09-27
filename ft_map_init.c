/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:06 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/27 22:20:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	buffer_update(char **buffer, char **map)
{
	char	*temp;

	temp = ft_strjoin(*map, *buffer);
	free(*map);
	*map = ft_strdup(temp);
	free(temp);
}

int	load_map(char *map_name, char **map)
{
	int		fd;
	int		read_call;
	char	*buffer;

	fd = open(map_name, O_RDONLY);
	*map = ft_calloc(1, 1);
	buffer = malloc(100);
	read_call = read(fd, buffer, 99);
	while (read_call > 0)
	{
		buffer[read_call] = '\0';
		buffer_update(&buffer, map);
		read_call = read(fd, buffer, 99);
	}
	close(fd);
	free (buffer);
	if (fd == -1 || read_call == -1)
		return (-1);
	return (0);
}

int	map_init(char *map_name, char **map_values)
{
	if (ft_strchr(map_name, '.') <= 0 || ft_memcmp(ft_strrchr(map_name, '.'), ".cub", 4) != 0)
	{
		ft_putendl_fd("Error\nMap extension not '.cub'", 2);
		exit(1);
	}
	if (load_map(map_name, map_values) == -1)
	{
		ft_putendl_fd("Error\nBad file.", 2);
		exit(1);
	}
	if (*map_values[0] < 32 && *map_values[0] >= 9)
	{
		ft_putendl_fd("Error\nBad file.", 2);
		exit(1);
	}
	return (0);
}
