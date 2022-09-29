/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:31:12 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/29 14:43:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

int ft_map_extantion_handle(void)
{
	ft_putendl_fd("Error\nMap extension not '.cub'", 2);
	return (-1);
}

int ft_bad_file_handle(void)
{
	ft_putendl_fd("Error\nBad file.", 2);
	return (-1);
}

int	ft_bad_character_handle(void)
{
	ft_putendl_fd("Error\nBad charcter.", 2);
	return (-1);
}