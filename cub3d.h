/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/10/01 21:18:46 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct cub3d
{
	float		x;
	float		y;
	int			background;
	int			width;
	int			color;
	void		*mlx;
	void		*win;
	void		*img;
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
int		map_init(char *map_name, char **map_values);
void	key_input(t_cub3d *cub3d);
int		ft_map_extantion_handle(void);
int		ft_bad_file_handle(void);
int		ft_bad_character_handle(void);
// void 	ft_put_protect(t_cub3d cub3d, int x, int y, int width);
// void	ft_map_render(t_cub3d cub3d);
// void 	ft_protect(t_cub3d cub3d, int x, int y, int width, int color);
// void ft_put_map(t_cub3d cub3d);
#endif