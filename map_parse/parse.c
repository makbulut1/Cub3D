/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:05:39 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/09 12:33:51 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

static char	*space_del(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = -1;
	j = 0;
	new_str = malloc(sizeof(char) * 75);
	while (str[++i])
	{
		new_str[j] = str[i];
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			i--;
		}
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*add_no_space(char	*str)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 0;
	j = 0;
	k = 0;
	temp = str;
	while (temp[i] == ' ')
		i++;
	//i -= (i > 0);
	j = i;
	while (temp[i])
		i++;
	i = ft_strlen(temp) - 1;
	while (temp[i] == ' ')
		i--;
	i++;
	while (j < i)
		str[k++] = temp[j++];
	str[k] = '\0';
	return (str);
}

static void	extension_control(t_game *game)
{
	if (game->no[3] != '.' || game->no[4] != '/' || \
	game->so[3] != '.' || game->so[4] != '/' || game->we[3] != '.' || \
	game->we[4] != '/' || game->ea[3] != '.' || game->ea[4] != '/')
		err(game, '2');
}

static void	parse_control(t_game *game)
{
	game->no = add_no_space(game->no);
	game->so = add_no_space(game->so);
	game->we = add_no_space(game->we);
	game->ea = add_no_space(game->ea);
	game->f = add_no_space(game->f);
	game->c = add_no_space(game->c);
	game->no = space_del(game->no);
	game->so = space_del(game->so);
	game->we = space_del(game->we);
	game->ea = space_del(game->ea);
	game->f = space_del(game->f);
	game->c = space_del(game->c);
	extension_control(game);
}

void	parse(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' && game->map[i][j + 1] == 'O')
				game->no = ft_strdup(game->map[i]);
			else if (game->map[i][j] == 'S' && game->map[i][j + 1] == 'O')
				game->so = ft_strdup(game->map[i]);
			else if (game->map[i][j] == 'W' && game->map[i][j + 1] == 'E')
				game->we = ft_strdup(game->map[i]);
			else if (game->map[i][j] == 'E' && game->map[i][j + 1] == 'A')
				game->ea = ft_strdup(game->map[i]);
			else if (game->map[i][j] == 'F')
				game->f = ft_strdup(game->map[i]);
			else if (game->map[i][j] == 'C')
				game->c = ft_strdup(game->map[i]);
		}
	}
	map_check(game);
	parse_control(game);
}
