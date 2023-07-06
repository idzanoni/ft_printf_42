/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:36:51 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/05 20:31:58 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		arg_check(va_list ap, const char *print, int i);

int	ft_printf(const char *print, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, print);
	i = 0;
	count = 0;
	while (print[i] != '\0')
	{
		if (print[i] != '%')
			count += ft_putchar_ret(print[i]);
		if (print[i] == '%')
		{
			i++;
			count += arg_check(ap, print, i);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

int	arg_check(va_list ap, const char *print, int i)
{
	int	count;

	count = 0;
	if (print[i] == 'c')
		count += ft_putchar_ret(va_arg(ap, int));
	else if (print[i] == 's')
		count += ft_putstr_ret(va_arg(ap, char *));
	else if (print[i] == 'p')
		count += ft_put_p(va_arg(ap, size_t));
	else if (print[i] == 'd' || print[i] == 'i')
		count += ft_putnbr_ret(va_arg(ap, int));
	else if (print[i] == 'u')
		count += ft_putnbr_uns_ret(va_arg(ap, unsigned int));
	else if (print[i] == 'x')
		count += ft_putnbr_base_low(va_arg(ap, unsigned int));
	else if (print[i] == 'X')
		count += ft_putnbr_base_up(va_arg(ap, unsigned int));
	else if (print[i] == '%')
		count += ft_putchar_ret('%');
	else
		count += ft_putchar_ret('%');
	return (count);
}
