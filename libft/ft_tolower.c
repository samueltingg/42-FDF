/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:57:58 by sting             #+#    #+#             */
/*   Updated: 2023/10/18 09:57:58 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int main(void)
// {
//     printf ("%c\n", ft_tolower('1'));
//     printf ("%c\n", tolower('1'));
// }