/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:48:46 by sting             #+#    #+#             */
/*   Updated: 2023/10/25 16:48:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
[] test edge cases!!
*/

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;
	size_t	total_size;

	if (element_size != 0 && (num_elements > (UINT_MAX / element_size)))
		return (NULL);
	total_size = num_elements * element_size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

// NOT SURE if main func is correct
// #include <stdio.h>

// int main()
// {
//     size_t num_elements = 5;
//     size_t element_size = sizeof(int);

//     char *arr = (char *)ft_calloc(num_elements, element_size);
//     if (arr == NULL)
//         printf ("%s", "mem alloc fail");
//         return (1);
//     printf("%s", arr);
//     free(arr);
//     return (0);
// }

/*
- calloc -> "clear allocation"
- Memory allocated by calloc is initialized to zero

TO NOTE
- line 24: element != 0, cus dividing by 0 is math error
steps
1. use malloc to allocate size for all blocks
2. set it all to 0 using bzero
*/