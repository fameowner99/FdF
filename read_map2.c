/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:44:29 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 20:00:16 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				*new_node(t_point *tmp)
{
	tmp->next = (t_point *)malloc(sizeof(t_point));
	tmp = tmp->next;
	tmp->down = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_point				*set_start_values(t_point *point, t_limit *limit)
{
	limit->max_z = 0;
	limit->min_z = 0;
	point->next = NULL;
	point->down = NULL;
	return (point);
}

static void			present_color(t_point *tmp, char **values, int i)
{
	int				j;

	j = 0;
	tmp->color = 0xFFFFFF;
	while (values[i][j])
	{
		if (values[i][j] == ',')
		{
			tmp->color = check_color(values[i] + j + 1);
			break ;
		}
		++j;
	}
}

void				fill_xyz(t_read *read, t_point **tmp, char **values)
{
	(read->x > 0 || read->y > 0) ? *tmp = new_node(*tmp) : 0;
	(*tmp)->x = read->x++;
	(*tmp)->b = 1;
	(*tmp)->y = read->y;
	(*tmp)->z = ft_atoi(values[read->i]);
	(*tmp)->start_z = (*tmp)->z;
	present_color(*tmp, values, read->i++);
}
