/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 07:51:17 by makbulut          #+#    #+#             */
/*   Updated: 2022/11/23 21:13:08 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <math.h>

# include <../lib/minilibx/mlx.h>

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <macro.h>
# include <data_structure.h>
# include <init_data.h>
# include <render.h>
# include <clear_map.h>
# include <events.h>
# include <tools.h>
# include <parser.h>

void	init_image(t_data *data);
void	minimap_render(t_data *data);

#endif
