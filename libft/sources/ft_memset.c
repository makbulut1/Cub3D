/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:55:54 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:55:55 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (size > i)
	{
		((unsigned char *)ptr)[i] = (unsigned char) c;
		i++;
	}
	return (ptr);
}
