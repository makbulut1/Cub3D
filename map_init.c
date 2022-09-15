/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:06 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/15 23:45:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

int	map_extension_check(char *av)
{
	if (ft_memcmp(ft_strrchr(av, '.'), ".cub", 4))
	{
		ft_putendl_fd("\033[31mMap extension not '.cub'\x1b[0m", 2);
		exit(1);
	}
	return (0);
}

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
		return (1);
	return (0);
}

t_map	*map_init(t_map *map, char *av)
{
	map = malloc(sizeof(t_map) * 1);
	map->av = av;
	map->fd = open(map->av, O_RDONLY);
	if ((map_extension_check(map->av)))
	{
		ft_putendl_fd("\033[31mError\nMap extension not '.cub'\x1b[0m", 2);
		exit(1);
	}
	if (load_map(map->av, &map->map_values))
	{
		ft_putendl_fd("\033[31mError\nBad file.\x1b[0m", 2);
		exit(1);
	}
	map->map_len = ft_strlen(map->map_values);
	return (map);
}
