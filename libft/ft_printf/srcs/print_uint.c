/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:49:27 by sting             #+#    #+#             */
/*   Updated: 2023/11/09 09:17:40 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Flags invoved: '0', '-', width
// -> Same like %i/%d, just without '+' & 'sp'

int	print_uint(unsigned int n, t_flags f)
{
	f.nb = n;
	f.digit_count = digit_count_base(f.nb, 10);
	if (f.prec && f.prec_len == 0 && f.nb == 0)
	{
		write_padding(' ', f.width - f.plus);
		return (f.width);
	}
	if (f.width && (f.width > f.prec_len))
	{
		if (f.prec && (f.prec_len > f.digit_count))
			if_minus_print(&f, f.digit_count);
		else if (!f.prec || (f.prec_len <= f.digit_count))
			if_zero_or_minus_print(&f, f.digit_count);
	}
	else if (f.prec && (!f.width || (f.width <= f.prec_len)))
	{
		f.total_len += write_padding('0', f.prec_len - f.digit_count);
		ft_putnbr_long(f.nb);
	}
	else
		ft_putnbr_long(f.nb);
	return (f.total_len + f.digit_count);
}
