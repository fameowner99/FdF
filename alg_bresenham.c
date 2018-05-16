/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:34:27 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 14:28:43 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change(t_point *p1, t_point *p2, t_draw *draw)
{
	if (fabs(p1->x - p2->x) < fabs(p1->y - p2->y))
	{
		ft_swap(&p1->x, &p1->y);
		ft_swap(&p2->x, &p2->y);
		draw->b = 1;
	}
	if (p1->x > p2->x)
	{
		ft_swap(&p1->x, &p2->x);
		ft_swap(&p1->y, &p2->y);
	}
}

static void	set_draw(t_draw *draw, t_point p1, t_point p2)
{
	draw->dx = p2.x - p1.x;
	draw->dy = p2.y - p1.y;
	draw->derror = fabs(draw->dy) * 2.;
	draw->error = 0.;
	draw->x = p1.x;
	draw->y = p1.y;
}

void		draw_line(t_point p1, t_point p2, t_union un)
{
	t_draw draw;

	draw.b = 0;
	change(&p1, &p2, &draw);
	set_draw(&draw, p1, p2);
	while (draw.x < p2.x)
	{
		if (draw.b)
			ft_putpixel(un.img, draw.y, draw.x, un.color_on ?
						my_colors(p1, p2) : p1.color);
		else
			ft_putpixel(un.img, draw.x, draw.y, un.color_on ?
						my_colors(p1, p2) : p1.color);
		draw.error += draw.derror;
		if (draw.error > draw.dx)
		{
			draw.y += (p2.y > p1.y ? 1. : -1.);
			draw.error -= draw.dx * 2.;
		}
		++draw.x;
	}
}
