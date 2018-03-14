/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connecting_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:42:03 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/14 18:35:28 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		connect_lines(t_point *point, t_mlx obj)
{
	t_point	*tmp;

	tmp = point;
	while (tmp)
	{
		tmp->next ? draw_line(*tmp, *tmp->next, obj, 0xFFFFFF) : 0;
		tmp->down ? draw_line(*tmp, *tmp->down, obj, 0xFFFFFF) : 0;
		tmp = tmp->next;
	}
}
