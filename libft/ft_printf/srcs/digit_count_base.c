/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_count_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:19:13 by sting             #+#    #+#             */
/*   Updated: 2023/11/07 09:08:17 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	digit_count_base(long long nbr, int base)
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
