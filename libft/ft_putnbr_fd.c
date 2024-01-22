/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:36 by sting             #+#    #+#             */
/*   Updated: 2023/10/26 07:36:32 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}

// int main(void)
// {
//     ft_putnbr_fd(2147483647, 1);
//     write (1, "\n", 1);
// }

/*
PLAN
	*Recursion*

	123/10 = 12
*/