/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:13:11 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 19:58:56 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	f(int key, double *add, double *move)
{
	if (key == 123 || key == 126)
		*add = -20;
	if (key == 124 || key == 125)
		*add = 20;
	*move += *add;
	return (*add);
}

void			translate_map(t_union *un, int key)
{
	t_point		*tmp;
	double		add_x;
	double		add_y;

	tmp = un->point;
	if (key == 123)
		f(key, &add_x, &un->limit.move_x);
	else if (key == 124)
		f(key, &add_x, &un->limit.move_x);
	else if (key == 125)
		f(key, &add_y, &un->limit.move_y);
	else if (key == 126)
		f(key, &add_y, &un->limit.move_y);
	while (tmp)
	{
		tmp->x += add_x;
		tmp->y += add_y;
		tmp = tmp->next;
	}
	ft_clear_image(un->img);
	connect_lines(*un);
	mlx_put_image_to_window(un->mlx.init_ptr,
			un->mlx.window_ptr, un->img->new_image, 0, 0);
}
