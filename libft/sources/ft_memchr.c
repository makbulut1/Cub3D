/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:55:28 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:55:29 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	*ptr;

	while (size-- > 0)
	{
		ptr = (unsigned char *) str;
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		str++;
	}
	return (NULL);
}
