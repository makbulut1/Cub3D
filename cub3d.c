/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/28 18:13:29 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include "Libft/libft.h"

void cub3d_loop(t_map map)
{
	t_cub3d cub3d;

	(void)map;
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 1000, 1000, "CUB3D WINDOWS!!!");
	key_input(&cub3d);
	mlx_loop(cub3d.mlx);
}

void ft_parse_map(t_map *map)
{
	char *a = NULL;

	int	j = 0;
	int i = -1;
	if (ft_strnstr(map->map_values, "1\n", ft_strlen(map->map_values)) != NULL)
	{
		a = ft_strnstr(map->map_values, "1\n", ft_strlen(map->map_values));
		while (a[i++])
		{
			// printf("%c", a[i]);
			if (a[i] == 'F' || a[i] == 'C')
				j = 1;
		}
	}
	else if (ft_strnstr(map->map_values, "1111", ft_strlen(map->map_values)) != NULL)
	{
		a = ft_strnstr(map->map_values, "111\n", ft_strlen(map->map_values));
	}
	if (j == 1)
	{
		a++;
		if (ft_strnstr(a, "1111", ft_strlen(a)) != NULL)
		{
			a = ft_strnstr(a, "111\n", ft_strlen(a));
		}
		else if (ft_strnstr(a, "1\n", ft_strlen(a)) != NULL)
		{
			a = ft_strnstr(a, "1\n", ft_strlen(a));
		}
	}
	printf("%s", a);
	while (a[i++])
		if (a[i] == '\n' && a[i + 1] == '\n')
			exit(1);
	for (int i = 0; map->map_values[i]; i++)
	{
		if (map->map_values[i] == '\n' && map->map_values[i + 1] == '\0')
			exit(1);
	}
	map->all_map_file = ft_split(map->map_values, '\n');
}

int main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		if (map_init(av[1], &map.map_values))
			return (-1);
		ft_parse_map(&map);
		cub3d_loop(map);
	}
	return (0);
}
