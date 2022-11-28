/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyarikan <iyarikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:58:30 by iyarikan          #+#    #+#             */
/*   Updated: 2022/11/23 20:58:31 by iyarikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(int fd, char c, int *ret_val);
void	ft_putstr(int fd, char *str, int *ret_val);
size_t	ft_strlen(const char *str);
void	ft_convert(int fd, size_t num, char *repres, int *ret_val);
int		ft_printf(const char *str, ...);
void	ft_abs(int fd, int data, int *ret_val);

#endif