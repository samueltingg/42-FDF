/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:37:15 by sting             #+#    #+#             */
/*   Updated: 2023/10/18 11:28:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The	memmove(void) function copies len bytes from string src to string dst.
The two strings may overlap; the copy is always done in a non-destructive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == dst)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char source[] = "Hello,World,12345";
// 	// char    destination[12];
// 	// printf("Mine  : %s\n", ft_memmove(source + 6, source, 11));
// 	printf("Actual: %s\n", memmove(source + 6, source, 11));
// 	// printf("%s\n", destination);
// }

/*
- Backward copy -> dst address is later in memory than src
- Forward copy -> dst address is earlier in memory than src
*/