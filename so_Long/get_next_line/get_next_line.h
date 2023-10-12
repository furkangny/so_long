/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:05:05 by fgunay            #+#    #+#             */
/*   Updated: 2023/09/26 15:05:06 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen1(const char *str);
char	*ft_strjoin1(char *str, char *buff);
char	*ft_strchr(const char *str, int c);
char	*ft_line(char *str);
char	*ft_str(char *str);
char	*ft_read_buff(int fd, char *str);
char	*get_next_line(int fd);

#endif
