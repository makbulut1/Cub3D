/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/27 16:37:09 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct cub3d
{
	int			x;
	void		*mlx;
	void		*win;
}			t_cub3d;

typedef struct s_map
{
	int		fd;
	char	**all_map_file;
	char	*map_values;
	char	*av;
	int		map_len;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}				t_map;

int		map_extension_check(char *av);
int	map_init(char *map_name, char **map_values);
void	key_input(t_cub3d *cub3d);

#endif