/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:56:37 by sting             #+#    #+#             */
/*   Updated: 2023/11/08 15:56:56 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_long(long nb)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', 1);
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), 1);
	else
	{
		ft_putnbr_long((nb / 10));
		ft_putnbr_long((nb % 10));
	}
}
