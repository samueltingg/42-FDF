/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/23 15:15:47 by sting             #+#    #+#             */
/*   Updated: 2023/10/23 15:15:47 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- Seg fault -> when n = 1
- incorrect output for c = '\0'
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
//     const char str[] = {0, 1, 2 ,3 ,4 ,5};
//     int c = 2 + 256;
//     size_t n = 3;

//     printf ("Actual: %s\n", (char *)memchr(str, c, n));
//     // printf ("Mine: %s\n", (char *)ft_memchr(str, c, n));

// 	// printf ("%s\n", NULL);
// 	// printf ("%s\n", "\0");
// }
