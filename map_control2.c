/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:55:10 by iyarikan          #+#    #+#             */
/*   Updated: 2022/09/30 16:44:32 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_control(char *av)
{
	while (*av)
		av++;
	av--;
	while (*av)
	{
		//if (*av-- == 'b' && *av-- == 'u' && *av-- == 'c' && *av-- == '.')
		if (*av-- == 'b')
			if (*av-- == 'u')
				if (*av-- == 'c')
					if (*av-- == '.')
						return (0);
	}
	return (1);
}

static void	check(int *i, t_map *map)
{
	if (map->data->buff[*i] == 'F')
		map->data->control->f += 1;
	else if (map->data->buff[*i] == 'C')
		map->data->control->c += 1;
	else if (map->data->buff[*i] != '0' && map->data->buff[*i] != '1' \
	&& map->data->buff[*i] != '\n' && map->data->buff[*i] != ' ')
		err(map, '2');
}

void	character_init(t_map *map)
{
	map->control->no = 0;
	map->control->so = 0;
	map->control->we = 0;
	map->control->ea = 0;
	map->control->f = 0;
	map->control->c = 0;
}

void	check_chars(t_map *map)
{
	int	i;

	i = -1;
	character_init(map);
	while (map->data->buff[++i])
	{
		if (map->data->buff[i] == 'N' && map->data->buff[i + 1] == 'O')
			map->control->no++;
		else if (map->data->buff[i] == 'S' && map->data->buff[i + 1] == 'O')
			map->control->so++;
		else if (map->data->buff[i] == 'W' && map->data->buff[i + 1] == 'E')
			map->control->we++;
		else if (map->data->buff[i] == 'E' && map->data->buff[i + 1] == 'A')
			map->control->ea++;
		check(&i, map);
	}
	if (map->control->no == 1 && map->control->so == 1 && map->control->we && \
	map->control->ea == 1 && map->control->f && map->control->c)
		err(map, '2');
}
/*
static void	add(char *str, t_data *data)
{
	while (*str == ' ')
		str++;
	data = ft_strdup(str);
}*/


char	*add_(char  *data)
{
	int	i;
	int	len;
	char	*new_str;

	i = 0;
	len = ft_strlen(data);
	new_str = malloc(sizeof(char) * len + 1);
	while (data[i])
	{
		new_str[i] = data[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	line_add(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' && data->map[i][j + 1] == 'O')
				data->no = ft_strtrim(data->map[i], " ");
			else if (data->map[i][j] == 'S' && data->map[i][j + 1] == 'O')
				data->so = add_(data->map[i]);
			else if (data->map[i][j] == 'W' && data->map[i][j + 1] == 'E')
				data->we = add_(data->map[i]);
			else if (data->map[i][j] == 'E' && data->map[i][j + 1] == 'A')
				data->ea = add_(data->map[i]);
			else if (data->map[i][j] == 'F')
				data->f = add_(data->map[i]);
			else if (data->map[i][j] == 'C')
				data->c = add_(data->map[i]);
		}
	}
	/*i = 0;
	while (data->buff[++i])
	{
		if (data->buff[i] == '1')
		{
			data->new_map = ft_strstr(&data->buff[i], "1");
		//	break;
		}
	}*/
}
