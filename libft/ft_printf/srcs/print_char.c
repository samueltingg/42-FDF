/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:47:08 by sting             #+#    #+#             */
/*   Updated: 2023/11/08 16:37:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c, t_flags f)
{
	if (f.width)
	{
		if (f.minus == 1)
		{
			write(1, &c, 1);
			write_padding(' ', f.width - 1);
		}
		else
		{
			write_padding(' ', f.width - 1);
			write(1, &c, 1);
		}
	}
	else if (!f.width)
	{
		write(1, &c, 1);
		return (1);
	}
	return (f.width);
}
