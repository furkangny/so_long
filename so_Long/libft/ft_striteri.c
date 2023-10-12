/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:47:02 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/11 18:47:03 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
void ft_upper(unsigned int i,char *s)
{
	int x = 0;
	if(*s)
	{
		s[x]-=32;
	}
}
int	main ()
{
	char str[] = "furkan";
	ft_striteri(str,ft_upper);
	printf("%s",str);

}*/
