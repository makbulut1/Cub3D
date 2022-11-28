/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:17:26 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/22 21:41:19 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		event_up(int key, t_data *data);
int		event_down(int key, t_data *data);
int		update(t_data *data);
void	move(t_data *data, t_vector2f move);
void	event_handler(t_data *data);

#endif