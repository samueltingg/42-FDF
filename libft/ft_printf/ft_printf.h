/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:23:09 by sting             #+#    #+#             */
/*   Updated: 2024/01/11 16:12:16 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int		hash;
	int		space;
	int		zero;
	int		plus;
	int		minus;
	int		width;
	int		prec;
	int		prec_len;
	int		neg;

	int		pad_len;
	int		str_len;
	int		total_len;
	int		digit_count;
	long	nb;
	int		final_len;
}			t_flags;

t_flags		check_setup_flags(const char *str);

/**
 * @brief pads 'specified char' for 'count' times
 * 			| won't print for -ve count
 */
int			write_padding(char pad_char, int count);
int			digit_count_base(long long nbr, int base);

int			print_char(char c, t_flags flags);
int			print_str(char *str, t_flags flags);

int			print_ptr(unsigned long long ptr, t_flags flags);
void		ft_putnbr_base(unsigned long long nbr, char *base);

int			print_uint(unsigned int nb, t_flags flags);

int			print_int(int nb, t_flags flags);
void		ft_putnbr_long(long nb);
void		if_minus_print(t_flags *f, int digit_count);
void		if_zero_or_minus_print(t_flags *f, int digit_count);

int			print_hex(unsigned int nb, t_flags flags, char *base);
int			ft_printf(const char *str, ...);

#endif
