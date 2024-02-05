/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 07:51:22 by sting             #+#    #+#             */
/*   Updated: 2024/02/05 14:35:34 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_count_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
		count++;
	}
	if (count < 2)
		return (0);
	return (count);
}

int	base_index(char *base, char c)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	base_len;

	sign = 1;
	result = 0;
	base_len = check_count_base(base);
	if (check_count_base (base) == 0)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (base_index(base, *str) == -1)
			return (result * sign);
		result = (result * base_len) + (base_index(base, *str));
		str++;
	}
	return (result * sign);
}

// #include <stdio.h>

// int main(void)
// {
// 	char base[] = "0123456789ABCDEF";
//     char string[] = "0xFF0000";

//     printf("%i", ft_atoi_base(string, base));
// }


/* atoi_base: input from any base, output decimal
 * line 53: can't return 0, as 0 is part of index
 * line 80: when meet char of str not part of base, return result 
 * using pointer method instead of array saves 2 lines */
