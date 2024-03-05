/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:31 by sting             #+#    #+#             */
/*   Updated: 2024/03/05 13:06:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void	free_cord(t_vars *vars, t_cord ***cord)
{
	int	y;

	y = 0;
	while (y < vars->line_count)
	{
		free((*cord)[y]);
		y++;
	}
	free((*cord));
}

void	free_all_cord(t_vars *vars)
{
	free_cord(vars, &vars->cord);
	if (vars->flags.split_4_view == TRUE)
	{
		free_cord(vars, &vars->cord_back);
		free_cord(vars, &vars->cord_left);
		free_cord(vars, &vars->cord_right);
	}
}

void	free_all_splitview_cord(t_vars *vars)
{
	free_cord(vars, &vars->cord_back);
	free_cord(vars, &vars->cord_left);
	free_cord(vars, &vars->cord_right);
}
