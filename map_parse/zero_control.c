/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 06:25:24 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 12:38:09 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

static void	zero_left(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j])
		{
			if (game->new_map[i][j] == '0')
			{
				if (game->new_map[i][j - 1] == '1' || \
				game->new_map[i][j - 1] == '0' || \
				game->new_map[i][j - 1] == 'W' || \
				game->new_map[i][j - 1] == 'N' || \
				game->new_map[i][j - 1] == 'E' || \
				game->new_map[i][j - 1] == 'S')
					continue ;
				else
					map_err(game, '5');
			}
		}
	}
}

static void	zero_right(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j])
		{
			if (game->new_map[i][j] == '0')
			{
				if (game->new_map[i][j + 1] == '1' || \
				game->new_map[i][j + 1] == '0' || \
				game->new_map[i][j + 1] == 'W' || \
				game->new_map[i][j + 1] == 'N' || \
				game->new_map[i][j + 1] == 'E' || \
				game->new_map[i][j + 1] == 'S')
					continue ;
				else
					map_err(game, '5');
			}
		}
	}
}

static void	zero_before(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j])
		{
			if (game->new_map[i][j] == '0')
			{
				if (i - 1 != -1 && (game->new_map[i - 1][j] == '1' || \
				game->new_map[i - 1][j] == '0' || \
				game->new_map[i - 1][j] == 'W' || \
				game->new_map[i - 1][j] == 'N' \
				|| game->new_map[i - 1][j] == 'E' || \
				game->new_map[i - 1][j] == 'S'))
					continue ;
				else
					map_err(game, '5');
			}
		}
	}
}

static	void	control_check(t_game *game, int *i)
{
	int	j;

	j = -1;
	if (game->new_map[*i + 1] == 0)
		while (game->new_map[*i][++j])
			if (game->new_map[*i][j] == '0')
				map_err(game, '4');
}

static void	zero_after(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->new_map[++i])
	{
		j = -1;
		while (game->new_map[i][++j] && game->new_map[i + 1] != 0)
		{
			if (game->new_map[i][j] == '0')
			{
				if (game->new_map[i + 1][j] == '1' || \
				game->new_map[i + 1][j] == '0' || \
				game->new_map[i + 1][j] == 'W' || \
				game->new_map[i + 1][j] == 'N' || \
				game->new_map[i + 1][j] == 'E' || \
				game->new_map[i + 1][j] == 'S')
					continue ;
				else
					map_err(game, '5');
			}
		}
		control_check(game, &i);
	}
}

void	zero_control(t_game *game)
{
	zero_left(game);
	zero_right(game);
	zero_before(game);
	zero_after(game);
}
