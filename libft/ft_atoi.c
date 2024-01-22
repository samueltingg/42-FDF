/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:02:04 by sting             #+#    #+#             */
/*   Updated: 2023/10/20 09:43:07 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "\v\t -2147483647abc";
// 	printf("Actual: %i\n", atoi(str));
// 	printf("Mine:   %i\n", ft_atoi(str));
// }

/*
- only can have 1 '+' or '-'
- there are >1 -/+ it will return straightaway as it is not 0-9
*/

// MY longer method to check if >1 +/-
// if (str[i] == '-')
// 	sign *= -1;
// count = 0;
// while (str[i] == '+' || str[i] == '-')
// {
// 	i++;
// 	count++;
// }
// if (count >= 2)
// 	return (0);