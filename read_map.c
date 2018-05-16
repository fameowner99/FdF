/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:42:19 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/26 16:30:38 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		*clear_list(t_point *point)
{
	t_point		*tmp;

	while (point)
	{
		tmp = point;
		point = point->next;
		free(tmp);
	}
	return (NULL);
}

static t_point		*connect_structure(t_point *point, t_limit limit)
{
	t_point			*tmp;
	t_point			*fpoint;

	tmp = point;
	fpoint = point;
	if (tmp)
		tmp = tmp->next;
	while (tmp && tmp->x > 0)
		tmp = tmp->next;
	if (tmp)
	{
		while (tmp)
		{
			fpoint->down = tmp;
			tmp = tmp->next;
			fpoint = fpoint->next;
		}
		tmp = point;
		while (tmp)
		{
			(tmp->x == limit.max_x) ? tmp->b = 0 : 0;
			tmp = tmp->next;
		}
	}
	return (point);
}

static void			free_arr(char **values)
{
	int				i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		values[i] = NULL;
		++i;
	}
	free(values);
	values = NULL;
}

static void			set_val(t_read *read, t_limit **limit, int t)
{
	if (t == 0)
	{
		read->x = 0;
		read->i = 0;
	}
	if (t == 1)
	{
		read->x ? (*limit)->max_x = read->x - 1 : 0;
		(*limit)->max_y = read->y - 1;
	}
}

t_point				*read_map(int fd, t_limit *limit)
{
	char			*line;
	char			**values;
	t_read			read;
	t_point			*point;
	t_point			*tmp;

	point = (t_point *)malloc(sizeof(t_point));
	tmp = set_start_values(point, limit);
	read.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		set_val(&read, &limit, 0);
		values = ft_strsplit(line, ' ');
		free(line);
		while (values[read.i])
			fill_xyz(&read, &tmp, values);
		free_arr(values);
		if (read.y++ > 0 && read.n != read.x)
			return (clear_list(point));
		read.n = read.x;
	}
	if ((read.x == 0 && read.y == 0) || (read.x <= 1 && read.y == 1))
		return (clear_list(point));
	set_val(&read, &limit, 1);
	return (connect_structure(point, *limit));
}
