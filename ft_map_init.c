/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:06 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/19 19:56:23 by makbulut         ###   ########.fr       */
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

void	ft_map_check(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->all_map_file[i])
	{
		while (map->all_map_file[i][j] )
		{
			printf("%c", map->all_map_file[i][j]);
			j++;
		}
		i++;
	}
}

t_map	*map_init(t_map *map, char *av)
{
	map = malloc(sizeof(t_map) * 1);
	map->av = av;
	map->fd = open(map->av, O_RDONLY);
	if ((map_extension_check(map->av)))
	{
		ft_putendl_fd("Error\nMap extension not '.cub'", 2);
		exit(1);
	}
	if (load_map(map->av, &map->map_values))
	{
		ft_putendl_fd("Error\nBad file.", 2);
		exit(1);
	}
	if (map->map_values[0] <= 32 && map->map_values[0] >= 9)
	{
		ft_putendl_fd("Error\nBad file.", 2);
		exit(1);
	}
	map->map_len = ft_strlen(map->map_values);
	map->all_map_file = ft_split(map->map_values, '\n');
	ft_map_check(map);
	return (map);
}
