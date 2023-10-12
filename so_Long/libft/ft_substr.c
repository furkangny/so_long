/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:16:21 by fgunay            #+#    #+#             */
/*   Updated: 2023/07/10 11:16:23 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char	*str;
	size_t	slen;
	size_t	finish;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	finish = 0;
	if (start < slen)
		finish = (slen - start);
	if (finish > len)
		finish = len;
	str = (char *)malloc(sizeof(char) * (finish + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, finish + 1);
	return (str);
}

/*
int	main(void)
{
char str[] = "furkan";
printf("%s", ft_substr(str, 1,3));
return (0);
}
*/