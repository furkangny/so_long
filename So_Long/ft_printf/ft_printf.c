/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:18:22 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/22 00:20:13 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	control(char c, va_list ap)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += print_char(va_arg(ap, int));
	else if (c == 's')
		ret += print_string(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ret += print_signedint(va_arg(ap, int));
	else if (c == 'u')
		ret += print_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		ret += print_hex(va_arg(ap, unsigned int));
	else if (c == 'X')
		ret += print_upperhex(va_arg(ap, unsigned int));
	else if (c == 'p')
	{
		ret += print_string("0x");
		ret += print_pointer(va_arg(ap, unsigned long));
	}
	else if (c == '%')
		ret += print_char('%');
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	ap;

	ret = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += control(str[i], ap);
		}
		else
			ret += print_char(str[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
