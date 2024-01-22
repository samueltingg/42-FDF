/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:36:34 by sting             #+#    #+#             */
/*   Updated: 2023/10/23 11:36:27 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "Heollo";

// 	int c = '#';

//     printf ("Mine: %s\n", ft_strrchr(str, c));
//     printf ("Actual: %s\n", strrchr(str, c));
// }