/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:50:23 by sting             #+#    #+#             */
/*   Updated: 2023/11/09 09:16:57 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void	handle_pos_or_neg_nb(t_flags *f, int digit_count)
{
	if (f->nb >= 0)
	{
		if (f->space && !f->plus && f->nb >= 0)
			f->total_len += write(1, " ", 1);
		else if (f->plus && !f->space && f->nb >= 0)
			f->total_len = write(1, "+", 1);
	}
	else if (f->nb < 0)
	{
		f->neg = 1;
		f->space = 0;
		f->plus = 0;
		if ((f->width && f->zero) || (f->prec_len > digit_count))
		{
			f->nb = -(f->nb);
			if (!(f->width > f->prec_len && f->prec_len > digit_count)
				|| f->minus)
				f->total_len += write(1, "-", 1);
		}
		else
			f->total_len++;
	}
}

void	if_minus_print(t_flags *f, int digit_count)
{
	if (f->minus)
	{
		f->total_len += write_padding('0', f->prec_len - digit_count);
		ft_putnbr_long(f->nb);
		f->total_len += write_padding(' ', f->width - f->prec_len - f->neg);
	}
	else if (!f->minus)
	{
		f->total_len += write_padding(' ', f->width - f->prec_len - f->neg);
		if ((f->width > f->prec_len && f->prec_len > digit_count) && f->neg)
			f->total_len += write(1, "-", 1);
		f->total_len += write_padding('0', f->prec_len - digit_count);
		ft_putnbr_long(f->nb);
	}
}

void	if_zero_or_minus_print(t_flags *f, int digit_count)
{
	int	pad_len;

	pad_len = f->width - digit_count - f->neg - f->space - f->plus;
	if (f->zero && !f->minus)
	{
		f->total_len += write_padding('0', pad_len);
		ft_putnbr_long(f->nb);
	}
	else if (f->minus && !f->zero)
	{
		ft_putnbr_long(f->nb);
		f->total_len += write_padding(' ', pad_len);
	}
	else if (!f->minus && !f->zero)
	{
		f->total_len += write_padding(' ', pad_len);
		ft_putnbr_long(f->nb);
	}
}

int	print_int(int n, t_flags f)
{
	f.nb = n;
	f.digit_count = digit_count_base(f.nb, 10);
	handle_pos_or_neg_nb(&f, f.digit_count);
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

/*
STRUCTURE:
1. handle +ve nb
2. handle -ve nb
3. handle edge case
4. 
	if (width)
	{
		if (prec)
		else if (no prec)
	}
	else if (only prec)
	else (no flags)
------------------------
Cases:
1. for (width + zero) & prec
	'-' not connected from nbr
	print '- first, then putnbr(-nb)

2. for width (!zero)
	print all the flags, then print putnbr(nb), '-' printed in putnbr

3. Special Case (line 30 & 53): 
	-> neg nb
	-> width > prec_len (both > digit_count)
	- - - - - - - - - - - - -
	Solution = if width > prec_len, print '-' later on
	eg. printf(%010.5i, -42)
		  problem: [-   00042]
		  correct: [   -00042]
		-> correct: '-' not printed at very left(as default)

*/