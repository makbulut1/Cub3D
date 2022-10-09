/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:56:57 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 11:27:17 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

int	cub_control(char *av)
{
	while (*av)
		av++;
	av--;
	while (*av)
	{	
		if (*av-- == 'b')
			if (*av-- == 'u')
				if (*av-- == 'c')
					if (*av == '.')
						return (0);
		return (1);
	}
	return (0);
}

static void	value(t_game *game, char **data)
{
	int		i;
	int		j;
	int		num;

	i = -1;
	while (data[++i])
	{
		j = -1;
		while (data[i][++j])
			if (!ft_isdigit(data[i][j]))
				err(game, '4');
	}
	i = -1;
	while (data[++i])
	{
		num = ft_atoi(data[i]);
		if (num > 255 || num < 0)
			err(game, '3');
	}
	if (i != 3)
		err(game, '5');
}

void	value_control(t_game *game)
{
	char	**f;
	char	**c;

	f = malloc(sizeof(char) * 4);
	c = malloc(sizeof(char) * 4);
	f = ft_split(&(game)->f[2], ',');
	c = ft_split(&(game)->c[2], ',');
	value(game, f);
	value(game, c);
}

void	control_init(t_control *control)
{
	control->no = 0;
	control->so = 0;
	control->we = 0;
	control->ea = 0;
	control->f = 0;
	control->c = 0;
}

void	map_check(t_game *game)
{
	int			i;
	t_control	control;

	i = -1;
	control_init(&control);
	while (game->buff[++i])
	{
		if (game->buff[i] == 'N' && game->buff[i + 1] == 'O')
			control.no++;
		else if (game->buff[i] == 'S' && game->buff[i + 1] == 'O')
			control.so++;
		else if (game->buff[i] == 'W' && game->buff[i + 1] == 'E')
			control.we++;
		else if (game->buff[i] == 'E' && game->buff[i + 1] == 'A')
			control.ea++;
		else if (game->buff[i] == 'F')
			control.f++;
		else if (game->buff[i] == 'C')
			control.c++;
	}
	if (control.no != 1 || control.so != 1 || control.we != 1 || \
	control.ea != 1 || control.f != 1 || control.c != 1)
		err(game, '6');
}
