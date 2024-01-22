/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:27 by sting             #+#    #+#             */
/*   Updated: 2023/10/20 10:44:14 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
bzero() function writes n zeroed bytes to the string s.  
If n is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	char_array[5];
// 	int		i;

// 	bzero(char_array, sizeof(char_array));
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%c", char_array[i]);
// 		i++;
// 	}
// 	ft_bzero(char_array, sizeof(char_array));
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%c", char_array[i]);
// 		i++;
// 	}
// }

/*
line 22: can't typecast "s" with (int *) instead of (char *)
		bzero -> zero out a block of memory byte by byte
			using (int *) will zero out 4 bytes at a time
*/