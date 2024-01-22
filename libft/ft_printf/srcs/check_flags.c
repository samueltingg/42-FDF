/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:53 by sting             #+#    #+#             */
/*   Updated: 2023/11/09 11:31:29 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags	initialize_flags(void)
{
	t_flags	flags;

	flags.hash = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.prec = 0;
	flags.prec_len = 0;
	flags.neg = 0;
	flags.total_len = 0;
	return (flags);
}

void	turn_on_present_flags(const char **str, t_flags *flags)
{
	while (**str && (ft_strchr("# 0+-", **str) != NULL))
	{
		if (**str == '#')
			flags->hash = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '0')
			flags->zero = 1;
		else if (**str == '+')
			flags->plus = 1;
		else if (**str == '-')
			flags->minus = 1;
		(*str)++;
	}
}

t_flags	check_setup_flags(const char *str)
{
	t_flags	flags;

	flags = initialize_flags();
	turn_on_present_flags(&str, &flags);
	flags.width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '.')
	{
		flags.prec = 1;
		flags.prec_len = ft_atoi(str + 1);
		flags.zero = 0;
	}
	return (flags);
}

/*
NOTE:
line 57: zero ignored with prec

*/