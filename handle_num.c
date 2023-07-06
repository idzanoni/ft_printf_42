/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:29:40 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/05 20:30:23 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ret(int n)
{
	char	c;
	int		ret;

	ret = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		else
		{
			write(1, "-", 1);
			n = -n;
			ret++;
		}
	}
	if (n >= 10)
	{
		ret += ft_putnbr_ret(n / 10);
	}
	c = n % 10 + '0';
	ret += write(1, &c, 1);
	return (ret);
}

int	ft_putnbr_uns_ret(unsigned int n)
{
	char	c;
	int		ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_putnbr_ret(n / 10);
	}
	c = n % 10 + '0';
	ret += write(1, &c, 1);
	return (ret);
}

int	ft_putnbr_base_low(size_t nb)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
		ret += ft_putnbr_base_low(nb / 16);
	ret += write(1, &HEX_LOW[nb % 16], 1);
	return (ret);
}

int	ft_putnbr_base_up(size_t nb)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
		ret += ft_putnbr_base_up(nb / 16);
	ret += write(1, &HEX_UPP[nb % 16], 1);
	return (ret);
}

int	ft_put_p(size_t nb)
{
	int	ret;

	ret = 2;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ret += ft_putnbr_base_low(nb);
	return (ret);
}
