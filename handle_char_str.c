/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:29:58 by izanoni           #+#    #+#             */
/*   Updated: 2023/07/05 20:30:16 by izanoni          ###   ########.fr       */
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

int	ft_putstr_ret(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (ret);
	while (s[ret] != '\0')
	{
		write(1, &s[ret], 1);
		ret++;
	}
	return (ret);
}
