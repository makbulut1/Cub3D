/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:57:31 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:57:34 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	jndex;

	jndex = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && jndex < len)
	{
		index = 0;
		while (needle[index] && haystack[index] == needle[index]
			&& ((jndex + index) < len))
			index++;
		if (!needle[index])
			return ((char *)haystack);
		jndex++;
		haystack++;
	}
	return (0);
}
