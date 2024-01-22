/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:01:28 by sting             #+#    #+#             */
/*   Updated: 2023/10/19 09:24:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memcmp() function compares byte string s1 against byte string s2.
	Both strings are assumed to be n bytes long.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char s1[] = "";
//     char s2[] = "";
//     int n = 0;
//     printf ("Actual: %i\n", memcmp(s1, s2, n));
//     printf ("Mine: %i\n", ft_memcmp(s1, s2, n));
// }

/*
- Reason for typecasting pointer:
	compiler doesn't know size & type of objects being pointed to
	- cannot directly compare const void pointers or values
*/