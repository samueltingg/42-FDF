/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:23:06 by sting             #+#    #+#             */
/*   Updated: 2024/03/01 06:44:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// size_t n -> size of eg.array in bytes
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char source[] = "";
// 	char    destination[] = "";
// 	// printf("Mine  : %s\n", ft_memcpy(source + 6, source, 11 * sizeof(char)));
// 	printf("Actual: %s\n", memcpy(destination, source, 0 * sizeof(char)));
// 	// printf("%s\n", destination);
// }

/*
memcpy: copy specified no. of bytes from src to dst
			- can be any type of data, not just null-terminated strings

- Overlapping occurs when destination is pointing to an element within source
- Overlapping -> src & dest shsare a portion of same memory
- Copied data may overwrite data that hasn't been copied yet,
	-> incorrect results
*/
