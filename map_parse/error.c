/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:00:14 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/13 18:59:28 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

void	file_error(t_game *game, char code)
{
	(void)game;
	if (code == '1')
		ft_putstr_fd("Error!\nError: File Name Error!\n", 2);
	else if (code == '2')
		ft_putstr_fd("Error!\nError: Failed To Sort Space With Malloc.\n", 2);
	exit(1);
}

void	malloc_map(t_game *game)
{
	ft_putstr_fd("Error!\nError: Failed To Sort Space With Malloc.\n", 2);
	free(game->buff);
	exit(1);
}

void	malloc_new_map(t_game *game)
{
	ft_putstr_fd("Error!\nError: Failed To Sort Space With Malloc.\n", 2);
	free(game->buff);
	free_map(game);
	exit(1);
}

void	err(t_game *game, char code)
{
	if (code == '1')
		ft_putendl_fd("Error!\nError: Character Error!\n", 2);
	else if (code == '2')
		ft_putendl_fd("Error!\nError: File Extension Error!\n", 2);
	else if (code == '3')
		ft_putendl_fd("Error!\nError: Incorrect Color Code Identification!\n", 2);
	else if (code == '4')
		ft_putendl_fd("Error!\nError: Color Code Can Be Number Only!\n", 2);
	else if (code == '5')
		ft_putendl_fd("Error!\nError: Error in Color Code Parameter!\n", 2);
	else if (code == '6')
		ft_putendl_fd("Error!\nError: Inappropriate Character Used!\n", 2);
	else if (code == '7')
		ft_putendl_fd("Error!\nError: Multiple Identification in the \
Character's Position Code!\n", 2);
	free(game->buff);
	free_new_map(game);
	exit(1);
}

void	map_err(t_game *game, char code)
{
	if (code == '1')
		ft_putendl_fd("Error!\nError: The Left Character of the \
Space Cannot Be Zero!\n", 2);
	else if (code == '8')
		ft_putendl_fd("Error!\nError: Space Right Character Cannot Be \
Zero!\n", 2);
	else if (code == '3')
		ft_putendl_fd("Error!\nError: -1 Array Index Character of \
Space Cannot Be Zero!\n", 2);
	else if (code == '4')
		ft_putendl_fd("Error!\nError: +1 Array Index Character of \
Space Cannot Be Zero!\n", 2);
	else if (code == '5')
		ft_putendl_fd("Error!\nError: Failed to Create Wall!\n", 2);
	free(game->buff);
	free_new_map(game);
	exit(1);
}
