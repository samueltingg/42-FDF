/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:48:42 by sting             #+#    #+#             */
/*   Updated: 2023/11/08 16:39:54 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	digit_count_base_ptr(unsigned long long nbr, int base)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		count++;
	}
	return (count);
}

int	print_ptr(unsigned long long ptr, t_flags f)
{
	f.total_len = 0;
	if (f.width)
	{
		if (f.minus)
		{
			f.total_len += write(1, "0x", 2);
			ft_putnbr_base(ptr, "0123456789abcdef");
			f.total_len += write_padding(' ', f.width
					- digit_count_base_ptr(ptr, 16) - 2);
		}
		else
		{
			f.total_len += write_padding(' ', f.width
					- digit_count_base_ptr(ptr, 16) - 2);
			f.total_len += write(1, "0x", 2);
			ft_putnbr_base(ptr, "0123456789abcdef");
		}
	}
	else if (!f.width)
	{
		write(1, "0x", 2);
		ft_putnbr_base(ptr, "0123456789abcdef");
		return (digit_count_base_ptr(ptr, 16) + 2);
	}
	return (f.total_len + digit_count_base_ptr(ptr, 16));
}
