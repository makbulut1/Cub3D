/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:25 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:26 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	format_checker(char *filename)
{
	int		len;
	char	*extension;

	len = ft_strlen(filename);
	if (len <= 4)
		return (1);
	extension = (char *) &filename[len - 4];
	if (ft_strcmp(extension, ".cub"))
		return (1);
	return (0);
}

t_map	*create_map(char *filename)
{
	t_map	*map;
	int		fd;

	if (format_checker(filename))
	{	
		ft_putstr_fd("Error\nArgument Error\n", 2);
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (0 > fd)
	{
		ft_putstr_fd("Error\nFolder Error\n", 2);
		exit(1);
	}
	map = init_map(fd);
	if (map)
		get_position(map);
	return (map);
}
