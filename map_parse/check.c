/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:51:11 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 11:13:21 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

void	line_map(t_game *data)
{
	int	i;
	int	j;
	int	k;

	i = 5;
	j = 0;
	while (data->map[++i])
	{
		k = -1;
		data->new_map[j] = malloc(sizeof(char) * ft_strlen(data->map[i]) + 1);
		while (data->map[i][++k])
			data->new_map[j][k] = data->map[i][k];
		data->new_map[j][k] = '\0';
		j++;
	}
	i = 0;
	data->new_map[j] = 0;
}

static int	control(t_game *game, int i, int j)
{
	if (game->new_map[i][j] == '1' || game->new_map[i][j] == '0' || \
		game->new_map[i][j] == 'N' || game->new_map[i][j] == 'S' || \
		game->new_map[i][j] == 'W' || game->new_map[i][j] == 'E' || \
		game->new_map[i][j] == ' ' || game->new_map[i][j] == '\n')
		return (0);
	return (1);
}

void	character_control(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->new_map[++i])
	{
		j = 0;
		while (game->new_map[i][j])
		{
			if (!control(game, i, j))
			{
				if (game->new_map[i][j] == 'N' || game->new_map[i][j] == 'S' || \
				game->new_map[i][j] == 'W' || game->new_map[i][j] == 'E')
					count++;
				j++;
			}
			else
				err(game, '6');
		}
	}
	if (count != 1)
		err(game, '1');
}

void	check_chars(t_game *game)
{
	line_map(game);
	character_control(game);
}
/*
void	extra_line(t_game *game, char *av, int *line)
{
	int		count;
	int		fd;
	int		i;
	char	*temp;
	
	count = 0;
	fd = open(av, O_RDONLY);
    if (fd < 0)
 		file_error(game, '1');
	while (*line >= 0)	
    {
		temp = get_next_line(fd);
		if (count <= 5)
		{
			i = -1;
			while (temp[++i])
			{
				if (temp[i] == 'N' || temp[i] == 'S' || temp[i] == 'W' ||
				temp[i] == 'E' || temp[i] == 'F' || temp[i] == 'C')
				{
					i++;
					count++;
					break ;
				}
			}
		}
		else
			break;
		(*line)--;
	}
	
}*/