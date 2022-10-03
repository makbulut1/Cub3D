/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/10/03 16:41:36 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define PI 3.14159265359
#define W 13
#define A 0
#define S 1 
#define D 2

// int mapX = 8, mapY = 8, mapS = 64;

// float pdx = 3, pdy = 0, pa;

// int map1[] =
// 	{
// 		1,1,1,1,1,1,1,1,
// 		1,0,1,0,0,0,0,1,
// 		1,0,1,0,0,0,0,1,
// 		1,0,0,0,0,0,0,1,
// 		1,0,0,0,0,0,0,1,
// 		1,0,0,0,0,0,0,1,
// 		1,0,0,0,0,0,0,1,
// 		1,1,1,1,1,1,1,1
// };

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


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
	int			*colon_location;
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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_map_render(t_cub3d cub3d);
// void 	ft_put_protect(t_cub3d cub3d, int x, int y, int width);
// void	ft_map_render(t_cub3d cub3d);
// void 	ft_protect(t_cub3d cub3d, int x, int y, int width, int color);
// void ft_put_map(t_cub3d cub3d);
#endif