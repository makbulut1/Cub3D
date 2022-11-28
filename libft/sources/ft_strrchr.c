/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:57:37 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:57:39 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	position;

	position = ft_strlen(str);
	if (str)
	{
		while (str[position] != (char) c && position >= 0)
			position--;
		if (str[position] == (char)c)
			return ((char *) &str[position]);
		return (NULL);
	}
	return (NULL);
}
