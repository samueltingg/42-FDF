/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:51:11 by sting             #+#    #+#             */
/*   Updated: 2023/10/27 15:17:25 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (*str != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*str == c)
		{
			flag = 1;
		}
		str++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**load_strings(char const *s, char c, char **str_arr, int word_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		str_arr[i] = (char *)malloc(sizeof(char) * word_len(s, c) + 1);
		if (str_arr[i] == NULL)
			return (NULL);
		j = 0;
		while (*s != c && *s)
		{
			str_arr[i][j] = *s;
			j++;
			s++;
		}
		str_arr[i][j] = '\0';
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (str_arr == NULL)
		return (NULL);
	str_arr = load_strings(s, c, str_arr, word_count);
	return (str_arr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**str_arr;
// 	int		i;

// 	// char const  *str = "xhelloxxhelloxxxhx";
// 	// char c = 'x';
// 	printf("count_words: %d\n", count_words("    ", ' '));
// 	str_arr = ft_split("    ", ' ');
// 	i = 0;
// 	while (str_arr[i])
// 	{
// 		printf("str: %s\n", str_arr[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (str_arr[i] != NULL)
// 	{
// 		free(str_arr[i]);
// 		i++;
// 	}
// 	free(str_arr);
// }

/*
PLAN (ft_split)
	- functions
		1. count_words
	- To get size for malloc
		1. count_words
		2. strlen of each word
	- Use pointer method in ft_split func,
		- iterate str++
		[] create a func returns each word individually

	For each word
		1. iterate s to skip 'c'
		1. func -> count len of each word until reach 'c'
		2. malloc, transfer until reach 'c'

- line 56: cannot include str_arr[i] as while loop won't run,
	cuz all strings in str_arr are set to NULL by default
*/

// MY OLD COUNT_WORDS (using flag is better)
// static int	count_words(char const *str, char c)
// {
// 	int	count;
// 	int	i;
//
// 	i = 0;
// 	count = 0;
// 	if (str[i] == '\0')
// 		return (0);
// 	while (str[i] == c)
// 		i++;
// 	while (str[i])
// 	{
// 		if (str[i] == c && (str[i - 1]) != c)
// 			count++;
// 		i++;
// 	}
// 	if (str[i] == '\0' && (str[i - 1]) != c)
// 		count++;
// 	return (count);
// }