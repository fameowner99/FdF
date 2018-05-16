/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:59:13 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 16:00:08 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_oz(t_union un, int key)
{
	t_point	*tmp;
	double	tmp_value;
	double	oz;

	tmp = un.point;
	if (key == 89)
		oz = 0.15;
	else
		oz = -0.15;
	while (tmp)
	{
		tmp->x -= un.limit.max_x * un.limit.curr_zoom / 2. + un.limit.move_x;
		tmp->y -= un.limit.max_y * un.limit.curr_zoom / 2. + un.limit.move_y;
		tmp->z -= (un.limit.max_z - un.limit.min_z) / 2.;
		tmp_value = tmp->x;
		tmp->x = tmp->x * cos(oz) - tmp->y * sin(oz);
		tmp->y = tmp_value * sin(oz) + tmp->y * cos(oz);
		tmp->x += un.limit.max_x * un.limit.curr_zoom / 2. + un.limit.move_x;
		tmp->y += un.limit.max_y * un.limit.curr_zoom / 2. + un.limit.move_y;
		tmp->z += (un.limit.max_z - un.limit.min_z) / 2.;
		tmp = tmp->next;
	}
}

static void	ft_rotate_oy(t_union un, int key)
{
	t_point	*tmp;
	double	tmp_value;
	double	oy;

	tmp = un.point;
	if (key == 86)
		oy = 0.15;
	else
		oy = -0.15;
	while (tmp)
	{
		tmp->x -= un.limit.max_x * un.limit.curr_zoom / 2. + un.limit.move_x;
		tmp->y -= un.limit.max_y * un.limit.curr_zoom / 2. + un.limit.move_y;
		tmp->z -= (un.limit.max_z - un.limit.min_z) / 2.;
		tmp_value = tmp->x;
		tmp->x = tmp->x * cos(oy) + tmp->z * sin(oy);
		tmp->z = -tmp_value * sin(oy) + tmp->z * cos(oy);
		tmp->x += un.limit.max_x * un.limit.curr_zoom / 2. + un.limit.move_x;
		tmp->y += un.limit.max_y * un.limit.curr_zoom / 2. + un.limit.move_y;
		tmp->z += (un.limit.max_z - un.limit.min_z) / 2.;
		tmp = tmp->next;
	}
}

static void	ft_rotate_ox(t_union un, int key)
{
	t_point	*tmp;
	double	ox;
	double	tmp_value;

	tmp = un.point;
	if (key == 83)
		ox = 0.15;
	else
		ox = -0.15;
	while (tmp)
	{
		tmp->x -= un.limit.max_x * un.limit.curr_zoom / 2. + un.limit.move_x;
		tmp->y -= un.limit.max_y * un.limit.curr_zoom / 2. + un.limit.move_y;
		tmp->z -= (un.limit.max_z - un.limit.min_z) / 2.;
		tmp_value = tmp->y;
		tmp->y = tmp->y * cos(ox) + tmp->z * sin(ox);
		tmp->z = -tmp_value * sin(ox) + tmp->z * cos(ox);
		tmp->x += un.limit.max_x * un.limit.curr_zoom / 2. + un.limit.move_x;
		tmp->y += un.limit.max_y * un.limit.curr_zoom / 2. + un.limit.move_y;
		tmp->z += (un.limit.max_z - un.limit.min_z) / 2.;
		tmp = tmp->next;
	}
}

void		rotate(t_union un, int key)
{
	if (key == 83 || key == 84)
		ft_rotate_ox(un, key);
	else if (key == 86 || key == 87)
		ft_rotate_oy(un, key);
	else if (key == 89 || key == 91)
		ft_rotate_oz(un, key);
	ft_clear_image(un.img);
	connect_lines(un);
	mlx_put_image_to_window(un.mlx.init_ptr, un.mlx.window_ptr,
						un.img->new_image, 0, 0);
}
