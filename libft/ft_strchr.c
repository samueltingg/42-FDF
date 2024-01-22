/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:55:31 by sting             #+#    #+#             */
/*   Updated: 2023/10/24 16:47:23 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strchr() function locates the first occurrence of c (converted to a char) 
	in the string pointed to by s.  
	The terminating null character is considered to be part of the string; 
	therefore if c is `\0', the functions locate the terminating `\0'.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "tripouille";

// 	int c = 't' + 256;
// 	printf ("char: %c\n", c);

//     printf ("Mine: %s\n", ft_strchr(str, c));
//     printf ("Actual: %s\n", strchr(str, c));
// }

/*
line 26: account for checking of '\0'
*/

// MY INITIAL LONGER METHOD
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == (unsigned char)c)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }