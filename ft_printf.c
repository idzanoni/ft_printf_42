/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:36:51 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/11 21:20:51 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_check(va_list args, const char *input, int i);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!input)
		return (-1);
	va_start(args, input);
	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '%')
			count += ft_putchar_ret(input[i]);
		if (input[i] == '%')
		{
			i++;
			count += arg_check(args, input, i);
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	arg_check(va_list args, const char *input, int i)
{
	int	count;

	count = 0;
	if (input[i] == 'c')
		count += ft_putchar_ret(va_arg(args, int));
	else if (input[i] == 's')
		count += ft_putstr_ret(va_arg(args, char *));
	else if (input[i] == 'p')
		count += ft_put_p(va_arg(args, size_t));
	else if (input[i] == 'd' || input[i] == 'i')
		count += ft_putnbr_ret(va_arg(args, int));
	else if (input[i] == 'u')
		count += ft_putnbr_uns_ret(va_arg(args, unsigned int));
	else if (input[i] == 'x')
		count += ft_putnbr_base_low(va_arg(args, unsigned int));
	else if (input[i] == 'X')
		count += ft_putnbr_base_up(va_arg(args, unsigned int));
	else
		count += ft_putchar_ret('%');
	return (count);
}
