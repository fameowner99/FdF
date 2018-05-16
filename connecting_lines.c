/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connecting_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:42:03 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 15:01:35 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		connect_lines(t_union un)
{
	t_point	*tmp;

	tmp = un.point;
	while (tmp)
	{
		tmp->next && tmp->b ? draw_line(*tmp, *tmp->next, un) : 0;
		tmp->down ? draw_line(*tmp, *tmp->down, un) : 0;
		tmp = tmp->next;
	}
}
