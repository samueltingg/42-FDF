/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:02:40 by sting             #+#    #+#             */
/*   Updated: 2023/10/24 10:05:23 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while ((unsigned int)num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	long	nb;

	nb = (long)num;
	str = (char *)malloc(sizeof(char) * (count_length(nb) + 1));
	if (str == NULL)
		return (NULL);
	str[count_length(nb)] = '\0';
	i = count_length(nb) - 1;
	if (nb == 0)
	{
		str[0] = '0';
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     int num = -2147483648;
//     char    *ptr = ft_itoa(num);
//     printf ("%s\n", ptr);
//     printf ("%i\n", count_length(num));

//     free (ptr);
//     return (0);
// }

/*
- line 51: nb > 0 instead of i > 0 to cater for both +ve & -ve num
	when num +ve, while(i<0) only run till i = 1, skipping index 0
*/