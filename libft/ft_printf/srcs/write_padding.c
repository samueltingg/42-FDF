/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:54:06 by sting             #+#    #+#             */
/*   Updated: 2023/11/07 13:48:56 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_padding(char pad_char, int count)
{
	int	len;

	if (count < 0)
		return (0);
	len = count;
	while (count > 0)
	{
		write(1, &pad_char, 1);
		count--;
	}
	return (len);
}
