/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:59:10 by sting             #+#    #+#             */
/*   Updated: 2023/10/18 09:59:10 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
//     printf ("%c\n", ft_toupper('h'));
//     printf ("%c\n", toupper('h'));
// }