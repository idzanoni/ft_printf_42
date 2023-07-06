/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:30:16 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/05 20:22:33 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"

int		ft_printf(const char *input, ...);
int		ft_putchar_ret(char c);
int		ft_putstr_ret(char *s);
int		ft_putnbr_base_up(size_t nb);
int		ft_putnbr_base_low(size_t nb);
int		ft_putnbr_uns_ret(unsigned int n);
int		ft_putnbr_ret(int n);
int		ft_put_p(size_t nb);
int		arg_check(va_list ap, const char *print, int i);

#endif