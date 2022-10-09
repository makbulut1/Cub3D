/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:40:49 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 11:26:25 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

static size_t	ft_new_line(const char *s)
{
	int	i;
	int	new_line;

	i = 0;
	new_line = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			new_line++;
		i++;
	}
	return (new_line);
}

t_game	*file_(char *av, int *line)
{
	int		fd;
	int		i;
	t_game	*game;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		file_error(game, '1');
	game = malloc(sizeof(t_game));
	game->buff = malloc(9999);
	if (!game->buff)
		file_error(game, '2');
	i = read(fd, game->buff, 9999);
	game->buff[i] = '\0';
	close(fd);
	*line = ft_new_line(game->buff);
	i = *line;
	game->map = malloc(sizeof(char *) * i);
	if (!game->map)
		malloc_map(game);
	game->map = ft_split(game->buff, '\n');
	game->new_map = malloc(sizeof(char *) * i);
	if (!game->new_map)
		malloc_new_map(game);
	return (game);
}
