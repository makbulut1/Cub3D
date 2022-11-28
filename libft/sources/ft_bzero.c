/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:53:41 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:53:44 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) ptr;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (ptr);
}
