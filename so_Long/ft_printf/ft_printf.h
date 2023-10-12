/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:18:41 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/22 00:18:43 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_hex(unsigned int nb);
int	print_upperhex(unsigned int nb);
int	print_pointer(unsigned long p);
int	print_char(char c);
int	print_string(char *str);
int	digit(int nb);
int	print_signedint(int nb);
int	print_unsigned(unsigned int nb);
int	control(char c, va_list ap);

#endif
