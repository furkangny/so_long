/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:00:50 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/12 14:00:51 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)

{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int main()
{
	int myDescri=open("my.txt", O_RDWR | O_CREAT, 0777 );
	ft_putendl_fd("furkan",myDescri);


}
*/