/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:02:19 by sting             #+#    #+#             */
/*   Updated: 2023/10/17 15:55:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	char_array[5];
// 	int		i;

// 	memset(char_array, 65, sizeof(char_array));
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%c", char_array[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_memset(char_array, 65, sizeof(char_array));
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%c", char_array[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

/*
eg. int c = 65, when printf(%i, ...) why doesn't it print 6565656565
line 22: why can't I use this instead? (int *)ptr)[i] = c;
line 22: c can represent char value altought define as int
line 23: c is explicitly casted unsigned char
*/