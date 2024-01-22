/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:51:04 by sting             #+#    #+#             */
/*   Updated: 2023/11/09 09:30:29 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_hash_flag(t_flags *f, unsigned int n, char *base)
{
	if (f->hash && n != 0)
	{
		if (ft_strncmp(base, "0123456789abcdef", 16) == 0)
			f->total_len += write(1, "0x", 2);
		else
			f->total_len += write(1, "0X", 2);
	}
}

static void	if_minus_print_hex(t_flags *f, int digit_count, char *base)
{
	if (f->minus)
	{
		f->total_len += write_padding('0', f->prec_len - digit_count);
		ft_putnbr_base(f->nb, base);
		f->total_len += write_padding(' ', f->width - f->prec_len - f->neg);
	}
	else if (!f->minus)
	{
		f->total_len += write_padding(' ', f->width - f->prec_len - f->neg);
		if ((f->width > f->prec_len && f->prec_len > digit_count) && f->neg)
			f->total_len += write(1, "-", 1);
		f->total_len += write_padding('0', f->prec_len - digit_count);
		ft_putnbr_base(f->nb, base);
	}
}

static void	if_zero_or_minus_print_hex(t_flags *f, int digit_count, char *base)
{
	int	pad_len;

	pad_len = f->width - digit_count - f->neg - f->space - f->plus;
	if (f->zero && !f->minus)
	{
		f->total_len += write_padding('0', pad_len);
		ft_putnbr_base(f->nb, base);
	}
	else if (f->minus && !f->zero)
	{
		ft_putnbr_base(f->nb, base);
		f->total_len += write_padding(' ', pad_len);
	}
	else if (!f->minus && !f->zero)
	{
		f->total_len += write_padding(' ', pad_len);
		ft_putnbr_base(f->nb, base);
	}
}

int	print_hex(unsigned int n, t_flags f, char *base)
{
	handle_hash_flag(&f, n, base);
	f.nb = n;
	f.digit_count = digit_count_base(f.nb, 16);
	if (f.prec && f.prec_len == 0 && f.nb == 0)
	{
		write_padding(' ', f.width - f.plus);
		return (f.width);
	}
	if (f.width && (f.width > f.prec_len))
	{
		if (f.prec && (f.prec_len > f.digit_count))
			if_minus_print_hex(&f, f.digit_count, base);
		else if (!f.prec || (f.prec_len <= f.digit_count))
			if_zero_or_minus_print_hex(&f, f.digit_count, base);
	}
	else if (f.prec && (!f.width || (f.width <= f.prec_len)))
	{
		f.total_len += write_padding('0', f.prec_len - f.digit_count);
		ft_putnbr_base(f.nb, base);
	}
	else
		ft_putnbr_base(f.nb, base);
	return (f.total_len + f.digit_count);
}
