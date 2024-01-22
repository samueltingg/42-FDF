/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:15:46 by sting             #+#    #+#             */
/*   Updated: 2023/10/26 16:39:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	if (j < i)
	{
		str = ft_substr(s1, i, 0);
		return (str);
	}
	len = j - i + 1;
	str = ft_substr(s1, i, len);
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*ptr;

// 	char    s1[] = "abecdaadba";
// 	char    set[] = "acb";
// 	ptr = ft_strtrim(s1, set);
// 	printf("res =[%s]\n", ptr);
// }

/*
How strtrim works
	- remove all characters seen in Hello that is within set
	- BUT, don't remove characters within set,
		that are between 2 characters not within set

Plan
	1. iterate from front to get first index of return string
			- if (s1[i] not in set)
					exit loop
	2. iterate from back to get last index of return string
	3. malloc str, calc length of str from "last index - first index"
	3. Using first & last index as a range, transfer values into malloced str
*/