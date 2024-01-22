/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:00:35 by sting             #+#    #+#             */
/*   Updated: 2023/10/26 07:55:11 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// static void	modify_char(unsigned int i, char *s)
// {
// 	if (s[i] >= 'a' && s[i] <= 'z')
// 		s[i] = s[i] - 32;
// }
// int main(void)
// {
//     char    *str = "hello";
//     ft_striteri(str, modify_char);
//     printf ("%s\n", str);
// }