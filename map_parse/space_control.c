/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 05:51:13 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 10:40:47 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

static void	space_left(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j])
		{
			if (game->new_map[i][j] == ' ')
			{
				if ((j - 1) == -1 || game->new_map[i][j - 1] == '1' ||
				game->new_map[i][j - 1] == ' ')
					continue ;
				else
					map_err(game, '1');
			}
		}
	}
}

static void	space_right(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j])
		{
			if (game->new_map[i][j] == ' ')
			{
				if (game->new_map[i][j + 1] == '\0' || \
				game->new_map[i][j + 1] == '1' || \
				game->new_map[i][j + 1] == ' ')
					continue ;
				else
					map_err(game, '8');
			}
		}
	}
}

static void	space_before(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j])
		{
			if (game->new_map[i][j] == ' ')
			{
				if (i - 1 == -1 || game->new_map[i - 1][j] == '1' || \
				game->new_map[i - 1][j] == ' ' || \
				game->new_map[i - 1][j] == '\0')
					continue ;
				else
					map_err(game, '3');
			}
			else
				j++;
		}
	}
}

static void	space_after(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j] && game->new_map[i + 1] != 0)
		{
			if (game->new_map[i][j] == ' ')
			{
				if ((i + 1) == '\0' || game->new_map[i + 1][j] == '1' ||
				game->new_map[i + 1][j] == ' ' || game->new_map[i + 1][j] == 0)
					continue ;
				else
					map_err(game, '4');
			}
		}
	}
}

void	space_control(t_game *game)
{
	space_left(game);
	space_right(game);
	space_before(game);
	space_after(game);
}
