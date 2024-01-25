/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:58:35 by sting             #+#    #+#             */
/*   Updated: 2024/01/24 20:48:14 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

long	check_count_base(char *base)
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
		i++;
		count++;
	}
	if (count < 2)
		return (0);
	return (count);
}

void	ft_putnbr_base(unsigned long long nb, char *base)
{
	unsigned long long	base_len;

	if (check_count_base(base) == 0)
		return ;
	base_len = (unsigned long long)check_count_base(base);
	if (nb < base_len)
		put_char(base[nb]);
	else
	{
		ft_putnbr_base((nb / base_len), base);
		ft_putnbr_base((nb % base_len), base);
	}
}

// int	main(void)
// {
// 	char base[] = "0123456789ABCDEF";
// 	unsigned long long	nbr = 140732893111904;
// 	ft_putnbr_base(nbr, base);
// }
