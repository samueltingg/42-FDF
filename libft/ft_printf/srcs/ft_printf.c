/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:36:06 by sting             #+#    #+#             */
/*   Updated: 2023/11/09 11:24:18 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_for_each_format(const char format, va_list args, t_flags flags)
{
	int	final_len;

	final_len = 0;
	if (format == 'c')
		final_len += print_char(va_arg(args, int), flags);
	else if (format == 's')
		final_len += print_str(va_arg(args, char *), flags);
	else if (format == 'p')
		final_len += print_ptr(va_arg(args, unsigned long long), flags);
	else if (format == 'u')
		final_len += print_uint(va_arg(args, unsigned long long), flags);
	else if (format == 'i' || format == 'd')
		final_len += print_int(va_arg(args, long), flags);
	else if (format == 'x')
		final_len += print_hex(va_arg(args, unsigned int), flags,
				"0123456789abcdef");
	else if (format == 'X')
		final_len += print_hex(va_arg(args, unsigned int), flags,
				"0123456789ABCDEF");
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		final_len += 1;
	}
	return (final_len);
}

int	ft_printf(const char *str, ...)
{
	int		final_len;
	va_list	args;
	t_flags	flags;

	va_start(args, str);
	final_len = 0;
	while (*str)
	{
		if (*str != '%')
			final_len += write(1, str, 1);
		else
		{
			str++;
			flags = check_setup_flags(str);
			while (ft_strchr("cspiduxX%", *str) == NULL)
			{
				str++;
			}
			final_len += print_for_each_format(*str, args, flags);
		}
		str++;
	}
	va_end(args);
	return (final_len);
}
