/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:31:22 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 16:14:14 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	f(int key, t_point *tmp, t_union *un)
{
	if (key == 24)
	{
		tmp->z *= (double)(un->limit.zoom + 1) / un->limit.zoom;
		tmp->x *= (double)(un->limit.zoom + 1) / un->limit.zoom;
		tmp->y *= (double)(un->limit.zoom + 1) / un->limit.zoom;
	}
	else
	{
		tmp->z /= (double)(un->limit.zoom) / (un->limit.zoom - 1);
		tmp->x /= (double)(un->limit.zoom) / (un->limit.zoom - 1);
		tmp->y /= (double)(un->limit.zoom) / (un->limit.zoom - 1);
	}
}

void		zoom(t_union *un, int key)
{
	t_point	*tmp;

	tmp = un->point;
	while (tmp)
	{
		tmp->x -= un->limit.move_x;
		tmp->y -= un->limit.move_y;
		f(key, tmp, un);
		tmp->x += un->limit.move_x;
		tmp->y += un->limit.move_y;
		tmp = tmp->next;
	}
	if (key == 24)
		un->limit.curr_zoom *= (double)(un->limit.zoom + 1) / un->limit.zoom;
	else
		un->limit.curr_zoom /= (double)(un->limit.zoom) / (un->limit.zoom - 1);
	ft_clear_image(un->img);
	connect_lines(*un);
	mlx_put_image_to_window(un->mlx.init_ptr, un->mlx.window_ptr,
				un->img->new_image, 0, 0);
}
