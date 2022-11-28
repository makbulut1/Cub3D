/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:57:22 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:57:23 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if ((!str1 && !str2) || size < 1)
		return (0);
	while (size - 1 > i && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return ((unsigned char) str1[i] - (unsigned char)str2[i]);
}
