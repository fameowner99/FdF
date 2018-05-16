/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:49:49 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 15:07:41 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_to_centre(t_union *un)
{
	t_point	*tmp;

	tmp = un->point;
	while (tmp)
	{
		tmp->x += SIZE_X / 4.;
		tmp->y += SIZE_Y / 4.;
		tmp = tmp->next;
	}
	un->limit.move_x += SIZE_X / 4.;
	un->limit.move_y += SIZE_Y / 4.;
}

void		find_central_position(t_union *un)
{
	t_point	*tmp;
	int		m;

	tmp = un->point;
	m = 1;
	while ((m * un->limit.max_x) < SIZE_X / 2.
				&& (m * un->limit.max_y) < SIZE_Y / 2.)
		++m;
	while (tmp)
	{
		tmp->z *= m;
		tmp->x *= m;
		tmp->y *= m;
		tmp = tmp->next;
	}
	un->limit.max_x *= m;
	un->limit.max_y *= m;
	un->limit.zoom = m;
	move_to_centre(un);
}

int			deal_key(int key, t_union *un)
{
	if (key == 53)
		exit(1);
	if (key == 123 || key == 126 || key == 124
			|| key == 125)
		translate_map(un, key);
	if (key == 24 || key == 27)
		zoom(un, key);
	if (key == 83 || key == 84 || key == 86 ||
			key == 87 || key == 89 || key == 91)
		rotate(*un, key);
	if (key == 7)
	{
		if (!un->color_on)
			un->color_on = 1;
		else
			un->color_on = 0;
		ft_clear_image(un->img);
		connect_lines(*un);
		mlx_put_image_to_window(un->mlx.init_ptr,
				un->mlx.window_ptr, un->img->new_image, 0, 0);
	}
	return (0);
}

void		fdf(t_union un)
{
	find_central_position(&un);
	connect_lines(un);
	mlx_hook(un.mlx.window_ptr, 2, 5, deal_key, &un);
	mlx_put_image_to_window(un.mlx.init_ptr,
				un.mlx.window_ptr, un.img->new_image, 0, 0);
	mlx_loop(un.mlx.init_ptr);
}
