/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:56:47 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:56:49 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	leng;

	leng = ft_strlen(src) + 1;
	dest = malloc(sizeof(src[0]) * leng);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, leng);
	return (dest);
}
