/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:34:27 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/14 18:26:55 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void		draw_line(t_point p1, t_point p2, t_mlx obj, int colour)
{
	double	dx;
	double	dy;
	double	i;
	double	j;
	int b;
	double x;
	double y;

	b = 0;
	if (ft_abs(p1.x - p2.x) < ft_abs(p1.y - p2.y))
	{
		ft_swap(&p1.x, &p1.y);
		ft_swap(&p2.x, &p2.y);
		b = 1;
	}
	if (p1.x > p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
	}
	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	i = ft_abs(dy) * 2.;
	
	j = 0.;
	x = p1.x;
	y = p1.y;
	while (x < p2.x)
	{
		if (b)
			mlx_pixel_put(obj.mlx, obj.window, x, y, colour);
		else
			mlx_pixel_put(obj.mlx, obj.window, y, x, colour);
		j += i;
		if (j > dx)
		{
			y += (p2.y > p1.y ? 1. : -1.);
			j -= dx * 2.;
		}
		++x;		
	}
}
