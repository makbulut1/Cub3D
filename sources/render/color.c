/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:46 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:52:47 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	color_dark(int color, float dark)
{
	int	r;
	int	g;
	int	b;

	r = color & 0x000000FF;
	r *= dark;
	g = (color & 0x0000FF00) >> 8;
	g *= dark;
	b = (color & 0x00FF0000) >> 16;
	b *= dark;
	return (r | (g << 8) | (b << 16));
}
