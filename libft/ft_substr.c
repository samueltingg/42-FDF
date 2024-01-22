/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:10:56 by sting             #+#    #+#             */
/*   Updated: 2023/10/24 16:01:16 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>

// int main(void)
// {
// //     char const  *s = "Hello";
// //     unsigned int    start = 3;
// //     size_t  len = 6;

// //     printf ("%s\n", ft_substr(s, start, len));
// 	char	*str = "12345";
// 	size_t	size = 10;
// 	printf ("%s\n", ft_substr(str, 10, size));
// }

/*
- len -> max length of substring

- line 24: why "else if" instead of "if"
	- if remain as "if", "len = ft_strlen(s) - start"
		"len" will be negative as start > ft_strlen(s)
		malloc(-ve) is invalid
*/