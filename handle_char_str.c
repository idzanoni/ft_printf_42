/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:29:58 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/06 13:15:55 by izanoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_ret(char c)
{
	int	ret;

	ret = 1;
	write(1, &c, 1);
	return (ret);
}

int	ft_putstr_ret(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[ret] != '\0')
	{
		write(1, &str[ret], 1);
		ret++;
	}
	return (ret);
}
