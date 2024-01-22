/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:27:30 by sting             #+#    #+#             */
/*   Updated: 2023/10/24 09:32:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strnstr() function locates the first occurrence of the null-terminated
		string needle in the string haystack,
		where not more than len characters are searched.
		Characters that appear after a `\0' character are not searched.

If needle is an empty string, haystack is returned;
	if needle occurs nowhere in haystack, NULL is returned;
	otherwise a pointer to the first character of the first
	occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (len && str[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && str[j + i] == to_find[j] && to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str1[11] = "dog or egg";
// 	char str2[] = "or";
// 	char str3[11] = "dog or egg";
// 	size_t len = 6;

// // // 	printf("replica      : %s\n", ft_strnstr(str1, str2, len));
// // // 	printf("original func: %s\n", strnstr(str3, str2, len));

// 	// UNIT TEST
// 	// char	*s1 = "A";
// 	// size_t	max = strlen(s1) + 1;

// 	// char	*i1 = strnstr(s1, s1, max);
// 	// printf ("%s\n", i1);
// 	// char	*i2 = ft_strnstr(s1, s1, max);
// 	// printf ("%s\n", i2);
// 	// if (i1 == i2)
// 	// 	printf("i1 == i2");
// 	// else
// 	// 	printf("i1 != i2");

	// UNIT TEST
	// printf ("%s\n", strnstr(NULL, "fake", 0));
// 	printf ("%s\n", ft_strnstr(NULL, "fake", 0));

// 	return (0);
// }