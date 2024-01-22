/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:43:39 by sting             #+#    #+#             */
/*   Updated: 2023/10/23 15:30:44 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     // char s1[] = Hell;
//     // char s2[] = "Hello";
//     // int n = 5;
//     // printf ("Actual: %i\n", strncmp(s1, s2, n));
//     // printf ("Mine: %i\n", ft_strncmp(s1, s2, n));
// 	printf ("Actual: %i\n", strncmp("test\200", "test\0", 6));
//     printf ("Mine: %i\n", ft_strncmp("test\200", "test\0", 6));
// }

/*
- must typcast to "unsigned char" 
	as value pass >127 will overflow and become -ve
*/