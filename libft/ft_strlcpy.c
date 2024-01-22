/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:29:03 by sting             #+#    #+#             */
/*   Updated: 2023/10/23 15:16:29 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	size_t	dstsize = 0;
// 	char	dest[10]; memset(dest, 'A', 10);

// 	dstsize = 0;
// 	char source[] = "Hello";

// 	printf("Return value: %zu\n", ft_strlcpy(dest, source, dstsize));
// 	// printf ("Return value: %zu\n", strlcpy(dest, source, dstsize));
// 	// printf("dest: %s\n", dest);
// 	printf("dest[0]: %c\n", dest[0]);

// }

/*
- strlcpy return -> length of src
- If return value is >= dstsize, output string has been shortened.
  It is the caller's responsibility to handle this.

*/