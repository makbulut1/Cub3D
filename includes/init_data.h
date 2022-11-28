/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:19:35 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/22 17:23:59 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_DATA_H
# define INIT_DATA_H

# include <data_structure.h>

void	get_map(t_data *data, char **line);
void	get_args(t_data *data, t_map *map);
int		get_data(t_data *data, t_map *map);

#endif