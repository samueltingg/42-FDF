/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:47:53 by sting             #+#    #+#             */
/*   Updated: 2023/11/09 09:00:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	setup_flags_and_output_len(t_flags *f)
{
	if (f->prec_len > f->str_len)
		f->prec = 0;
	else if (f->width && f->prec)
	{
		f->pad_len = f->width - f->prec_len;
		f->str_len = f->prec_len;
	}
	if (f->width && !f->prec)
		f->pad_len = f->width - f->str_len;
}

int	print_str(char *str, t_flags f)
{
	if (!str)
		str = "(null)";
	f.str_len = ft_strlen(str);
	setup_flags_and_output_len(&f);
	if (f.width)
	{
		if (f.minus)
		{
			f.total_len += write(1, str, f.str_len);
			f.total_len += write_padding(' ', f.pad_len);
		}
		else
		{
			f.total_len += write_padding(' ', f.pad_len);
			f.total_len += write(1, str, f.str_len);
		}
	}
	else if (!f.width && f.prec)
		f.total_len += write(1, str, f.prec_len);
	else
		f.total_len += write(1, str, f.str_len);
	return (f.total_len);
}

/*
Flags involved: '-', width, prec

STRUCTURE:
1. turn of width & prec if
		- width < strlen
		- prec > strlen
2. (width is present), modify pad_len & str_len depending on presence of prec.

*/