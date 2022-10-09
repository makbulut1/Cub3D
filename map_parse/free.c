/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:14:10 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/06 15:08:36 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
}

void	free_new_map(t_game *game)
{
	int	i;

	i = -1;
	while (game->new_map[++i])
		free(game->new_map[i]);
	free(game->new_map);
	free_map(game);
}
