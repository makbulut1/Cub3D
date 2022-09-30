/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/30 16:06:04 by iyarikan         ###   ########.fr       */
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

void ft_parse_map(void) //denemelik bir fonksiyon
{
	// char *a = NULL;
	// int	j = 0;
	// int i = -1;
	// if (ft_strnstr(map->map_values, "1\n", ft_strlen(map->map_values)) != NULL)
	// {
	// 	a = ft_strnstr(map->map_values, "1\n", ft_strlen(map->map_values));
	// 	while (a[i++])
	// 	{
	// 		if (a[i] == 'F' || a[i] == 'C')
	// 			j = 1;
	// 	}
	// }
	// else if (ft_strnstr(map->map_values, "1111", ft_strlen(map->map_values)) != NULL)
	// {
	// 	a = ft_strnstr(map->map_values, "111\n", ft_strlen(map->map_values));
	// }
	// if (j == 1)
	// {
	// 	a++;
	// 	if (ft_strnstr(a, "1111", ft_strlen(a)) != NULL)
	// 	{
	// 		a = ft_strnstr(a, "111\n", ft_strlen(a));
	// 	}
	// 	else if (ft_strnstr(a, "1\n", ft_strlen(a)) != NULL)
	// 	{
	// 		a = ft_strnstr(a, "1\n", ft_strlen(a));
	// 	}
	// }
	// while (a[i++])
	// 	if (a[i] == '\n' && a[i + 1] == '\n')
	// 		exit(1);
	// for (int i = 0; map->map_values[i]; i++)
	// {
	// 	if (map->map_values[i] == '\n' && map->map_values[i + 1] == '\0')
	// 		exit(1);
	// }
	// map->all_map_file = ft_split(map->map_values, '\n');
	// map->all_map_file[0] = ft_strtrim(map->all_map_file[0], " ");
	// map->all_map_file[0] = ft_strtrim(map->all_map_file[0], "NO");
	// map->all_map_file[0] = ft_strtrim(map->all_map_file[0], " ");
	// printf("%s", map->all_map_file[0]);
}

int main(int ac, char **av)
{
	t_map map;

	if (ac == 2)
	{
		//map.mlx = mlx_init();
		map_control(&map, av[1]);
		
		if (map_init(av[1], &map.map_values))
			return (-1);
		//ft_parse_map(&map);
		cub3d_loop(map);
	}
	return (0);
}
