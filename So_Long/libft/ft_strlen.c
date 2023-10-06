/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:42:49 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/03 15:43:04 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)

{
	size_t	l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}
/*
#include <stdio.h>
int	main(void)
{
		char str[] = "furkangunay";
	size_t length = ft_strlen(str);
	printf("Length of the string: %zu\n", length);
	return (0);
}*/