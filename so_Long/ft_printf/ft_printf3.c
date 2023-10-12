/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:19:02 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/22 00:19:03 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	digit(int nb)
{
	int	dig;

	if (nb == 0 || nb == 1)
		return (1);
	dig = 0;
	if (nb < 0)
	{
		dig++;
		nb = -nb;
	}
	while (nb)
	{
		dig++;
		nb = nb / 10;
	}
	return (dig);
}

int	print_signedint(int nb)
{
	int		ret;
	char	t;

	ret = digit(nb);
	if (nb >= 0 && nb <= 9)
	{
		t = nb + '0';
		print_char(t);
	}
	else if (nb == -2147483648)
		print_string("-2147483648");
	else if (nb < 0)
	{
		print_char('-');
		print_signedint(-nb);
	}
	else
	{
		print_signedint(nb / 10);
		print_signedint(nb % 10);
	}
	return (ret);
}

int	print_unsigned(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb <= 9)
		ret += print_char(nb + '0');
	else
	{
		ret += print_unsigned(nb / 10);
		ret += print_unsigned(nb % 10);
	}
	return (ret);
}
