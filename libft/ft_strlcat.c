/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:30:05 by sting             #+#    #+#             */
/*   Updated: 2023/10/25 15:58:26 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ori_dst_len;

	if (!dstsize)
		return (ft_strlen(src));
	ori_dst_len = ft_strlen(dst);
	i = ori_dst_len;
	j = 0;
	if (dstsize <= ori_dst_len)
		return (dstsize + ft_strlen(src));
	while (((i + 1) < dstsize) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ori_dst_len + ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char dest[] = "123456789012345";
// 	char src[] = "hello";

// 	printf("strlcat: %i\n", (int)ft_strlcat(dest,src,5));
// 	printf("dest= %s\n", dest);

	// char dst[7] = "Call";
	// char src[] = "911";
	// char dst1[7] = "Call";
	// char src1[] = "911";

	// UNIT TEST
	// char dst[7] = "Call";
	// char src[] = "911";
	// char dst1[7] = "Call";
	// char src1[] = "911";

	// printf("Mine: %zu\n", ft_strlcat(NULL, src, 0));
	// printf("%s\n", dst);
	// printf("Actual: %lu\n", strlcat(NULL, src1, 0));
	// printf("%s\n", dst1);

	// TEST 3
	// char dst[30]; memset(dst, 0, 30); dst[0] = 'B';
	// memset(dst, 'B', 4);
	// char * src = (char *)"AAAAAAAAA";
	// char dst1[30]; memset(dst1, 0, 30); dst1[0] = 'B';
	// memset(dst1, 'B', 4);
	// char * src1 = (char *)"AAAAAAAAA";

	// printf("%zu\n", strlen(dst));

	// printf("Mine: %zu\n", ft_strlcat(dst, src, 3));
	// printf("%s\n", dst);
	// printf("Actual: %lu\n", strlcat(dst1, src1, 3));
	// printf("%s\n", dst1);

	// printf("%i", strncmp(dst, "BBBB", 1));

	// // TEST 4
	// char dst[30]; memset(dst, 0, 30); 	dst[0] = 'B';
	// memset(dst, 'B', 4);
	// char * src = (char *)"AAAAAAAAA";
	// char dst1[30]; memset(dst1, 0, 30); 	dst1[0] = 'B';
	// memset(dst1, 'B', 4);
	// char * src1 = (char *)"AAAAAAAAA";

	// printf("%zu\n", strlen(dst));

	// printf("Mine: %zu\n", ft_strlcat(dst, src, 6));
	// printf("%s\n", dst);
	// printf("Actual: %lu\n", strlcat(dst1, src1, 6));
// 	// printf("%s\n", dst1);

// 	// printf("%i", strncmp(dst, "BBBBA", 1));

	// war machine
// 	char	*dest;
// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 'r', 15);
// 	ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	printf ("%s", dest);
// 	return (0);
// }

/*
- line 26: if statement as strlcat
	- dstsize should be always > than strlen(dst)
		- if dstsize <= ori_destlen, 
			there's no more space to concatenate another str

- line 21: if dstsize = 0 / if dst is NULL 
*/