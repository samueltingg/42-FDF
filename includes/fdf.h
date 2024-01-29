/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:25:04 by sting             #+#    #+#             */
/*   Updated: 2024/01/29 16:44:02 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include ".././libft/libft.h"
# include "macros.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// ^can also use <mlx.h>, but only in 42 macs

typedef struct s_cord
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_cord;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_vars;
/*
- line length: amount of bytes taken by one row of our image
*/
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
- x & y : starting coordinates
*/
typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

#endif
