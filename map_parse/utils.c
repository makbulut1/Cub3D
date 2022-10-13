/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:19:08 by iyarikan          #+#    #+#             */
/*   Updated: 2022/10/13 17:20:31 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

char *gnl(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	character;
    char 	*buffer = malloc(10000);

    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}