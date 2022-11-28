/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:54:49 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:54:50 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

static int	ft_count_leng(int num)
{
	int	i;

	i = 0;
	while (num > 9 || num < -9)
	{
		num = num / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int value)
{
	char	*ret;
	int		leng;
	int		is_negative;

	is_negative = value < 0;
	leng = ft_count_leng(value) + is_negative;
	ret = (char *) malloc(sizeof(char) * (leng + 1));
	if (!ret)
		return (NULL);
	ret[leng--] = '\0';
	while (leng >= 0)
	{
		ret[leng] = ft_abs(value % 10) + '0';
		value /= 10;
		leng--;
	}
	if (is_negative)
		ret[0] = '-';
	return (ret);
}
