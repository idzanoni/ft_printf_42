/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:29:40 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/06 13:17:59 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ret(int num)
{
	char	c;
	int		ret;

	ret = 0;
	if (num < 0)
	{
		if (num == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		else
		{
			write(1, "-", 1);
			num = -num;
			ret++;
		}
	}
	if (num >= 10)
	{
		ret += ft_putnbr_ret(num / 10);
	}
	c = num % 10 + '0';
	ret += write(1, &c, 1);
	return (ret);
}

int	ft_putnbr_uns_ret(unsigned int num)
{
	char	c;
	int		ret;

	ret = 0;
	if (num >= 10)
	{
		ret += ft_putnbr_ret(num / 10);
	}
	c = num % 10 + '0';
	ret += write(1, &c, 1);
	return (ret);
}

int	ft_putnbr_base_low(size_t num)
{
	int	ret;

	ret = 0;
	if (num >= 16)
		ret += ft_putnbr_base_low(num / 16);
	ret += write(1, &HEX_LOW[num % 16], 1);
	return (ret);
}

int	ft_putnbr_base_up(size_t num)
{
	int	ret;

	ret = 0;
	if (num >= 16)
		ret += ft_putnbr_base_up(num / 16);
	ret += write(1, &HEX_UPP[num % 16], 1);
	return (ret);
}

int	ft_put_p(size_t num)
{
	int	ret;

	ret = 2;
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ret += ft_putnbr_base_low(num);
	return (ret);
}
