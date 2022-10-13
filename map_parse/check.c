/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:51:11 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/13 18:57:22 by iyarikan         ###   ########.fr       */
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

void	extra_line(char *av, t_game *game)
{
	int		i;
	int		j;
	int		fd;
	int		count;
	char	**temp;

	i = -1;
	count = ft_new_line(game->buff);
	temp = (char **)malloc(sizeof(char *) * count + 1);
	temp[count] = 0;
	fd = open(av, O_RDWR, 0777);
	while (++i <= count)
		temp[i] = gnl(fd);
	count = 0;
	while (temp[count])
		count++;
	count -= 2;
	while (temp[count][0] == '\n')
		count--;
	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			while (temp[i][j] == ' ' || temp[i][j] == '\t' || temp[i][j] == '\n')
				j++;
			if (temp[i][j] == 'N' || temp[i][j] == 'S' || temp[i][j] == 'W' || \
				temp[i][j] == 'E' || temp[i][j] == 'F' || temp[i][j] == 'C')
				break;
			if (temp[i][j] == '1')
			{
				while (i < count)
				{
					if (temp[i][0] == '\n')
					{
						i = -1;
						while (temp[++i])
							free(temp[i]);
						free(temp);
						err(game, '1');
					}
					i++;
				}
				
			}
		}
	}
	while (temp[++i])
		free(temp[i]);
	free(temp);
}
