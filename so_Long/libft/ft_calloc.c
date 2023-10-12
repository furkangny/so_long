/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:17:51 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/07 15:17:52 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_arr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ret_arr = malloc(count * size);
	if (!ret_arr)
		return (NULL);
	ft_bzero(ret_arr, count * size);
	return (ret_arr);
}
/*
int main()
{
	int *c;
	c=ft_calloc(5,sizeof(int));
	c[0]='c';
	printf("%c",c[0]);
	free(c);
}*/