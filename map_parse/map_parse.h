/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:41:29 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 10:21:51 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSE_H
# define MAP_PARSE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "../cub3d.h"
# include "../Libft/libft.h"

typedef struct s_control
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;

}	t_control;

typedef struct s_game
{
	struct t_control	*control;
	char				*buff;
	char				**map;
	char				**new_map;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
}				t_game;

void		map_control(char *av);
int			cub_control(char *av);
t_game		*file_(char *av, int *line);
void		check_chars(t_game *game);
void		parse(t_game *game);
void		game_init(t_game *game);
void		value_control(t_game *game);
void		map_check(t_game *game);
void		check_chars(t_game *game);
void		space_control(t_game *game);
void		zero_control(t_game *game);
void		extra_line(t_game *game, char *av, int *line);
char		*get_next_line(int fd);

void		free_map(t_game *game);
void		free_new_map(t_game *game);

void		file_error(t_game *game, char code);
void		malloc_map(t_game *game);
void		malloc_new_map(t_game *game);
void		err(t_game *game, char code);
void		map_err(t_game *game, char code);

#endif
