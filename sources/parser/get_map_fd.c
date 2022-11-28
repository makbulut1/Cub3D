/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:28 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:29 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_map_fd(t_map *map, int fd)
{
	char	*s;
	char	*tmp;

	tmp = ft_strdup("");
	s = NULL;
	while (!s)
		if (-1 == get_line(fd, &s, 0))
			return (-1);
	while (s)
	{
		tmp = join_and_free(tmp, s);
		get_line(fd, &s, 0);
	}
	while (!s)
		if (-1 == get_line(fd, &s, 0))
			break ;
	if (s)
	{
		free(s);
		free(tmp);
		return (-1);
	}
	map->data = ft_split(tmp, '\n');
	free(tmp);
	return (0);
}
