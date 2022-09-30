/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:06:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/30 16:41:44 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct cub3d
{
	int			x;
	void		*mlx;
	void		*win;
}			t_cub3d;

typedef struct s_map
{
	int				fd;
	char			**all_map_file;
	char			*map_values;
	char			*av;
	int				map_len;
	char			*buff;
	char			**map;
//	char			*NO;
//	char			*SO;
//	char			*WE;
//	char			*EA;
//	char			*F;
//	char			*C;
	struct s_data		*data;
	struct s_control	*control;
	
}				t_map;

typedef struct s_data
{
	char	*buff;
	char	**map;
	char	*new_map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		y;
	int		x;
	struct s_map	*s_map;
	struct s_control *control;
	
}				t_data;

typedef struct s_control
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;

}	t_control;


int		map_extension_check(char *av);
int		map_init(char *map_name, char **map_values);
void	key_input(t_cub3d *cub3d);
int		ft_map_extantion_handle(void);
int		ft_bad_file_handle(void);
int		ft_bad_character_handle(void);

void	map_control(t_map *map, char *av);
void	err(t_map *map, char error_code);
void	split_err(t_map *map);
void	malloc_err(t_map *map, int fd);
void	free_map(t_data *data);
void	check_chars(t_map *map);
int		cub_control(char *av);
void	line_add(t_data *data);

#endif