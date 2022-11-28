/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:53:16 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:53:17 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_line(int fd, char **str, int f)
{
	int		i;
	char	*s;

	i = -1;
	*str = get_next_line(fd);
	if (!*str)
		return (-1);
	if (f)
		s = ft_strtrim(*str, " \n\t\v\f\r");
	else
		s = ft_strdup(*str);
	free(*str);
	while (s && s[++i])
	{	
		if (!ft_isspace(s[i]))
		{
			*str = s;
			return (0);
		}
	}
	free(s);
	*str = NULL;
	return (0);
}
