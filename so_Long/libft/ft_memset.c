/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:04:56 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/03 16:04:58 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)

{
	char	*str;

	str = (char *)b;
	while (len > 0)
	{
		*str++ = c;
		len--;
	}
	return (b);
}
/*
int main ()
{
	char str[] = "furykangny";
	ft_memset (str, 'x', 5);
	printf("%s",str);

}*/