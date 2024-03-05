/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:50:13 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 13:23:52 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

int	get_red(int color)
{
	return (color >> 16);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	rgb_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	gradient(int startcolor, int endcolor, int len, int position)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)(get_red(endcolor) - get_red(startcolor))
		/ (double)len;
	increment[1] = (double)(get_green(endcolor) - get_green(startcolor))
		/ (double)len;
	increment[2] = (double)(get_blue(endcolor) - get_blue(startcolor))
		/ (double)len;
	new[0] = get_red(startcolor) + round(position * increment[0]);
	new[1] = get_green(startcolor) + round(position * increment[1]);
	new[2] = get_blue(startcolor) + round(position * increment[2]);
	newcolor = rgb_color(new[0], new[1], new[2]);
	return (newcolor);
}
