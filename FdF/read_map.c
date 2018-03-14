/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:42:19 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/14 16:42:32 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point *clear_list(t_point *point)
{
    t_point *tmp;

    while (point)
    {
        tmp = point;
        point = point->next;
        free(tmp);
        tmp = NULL;
    }
    return (NULL);
}

static t_point		*connect_structure(t_point *point)
{
    t_point *tmp;
    t_point	*fpoint;

    tmp = point;
    fpoint = point;
    if (tmp)
        tmp = tmp->next;
    while (tmp && tmp->y != 0)
        tmp = tmp->next;
    if (tmp)
    {
        while (tmp)
        {
            fpoint->down = tmp;
            tmp = tmp->next;
            fpoint = fpoint->next;
        }
    }
    return (point);
}

t_point		*read_map(int fd)
{
	char	*line;
	char	**values;
	double	x;
	double	y;
    double  n;
	t_point *point;
	t_point	*tmp;
	int	i;

	x = 0;
	point = (t_point *)malloc(sizeof(t_point));
	tmp = point;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line); 
		y = 0;
		i = 0;
		values = ft_strsplit(line, ' ');
		while (values[i])
		{
			tmp->x = x;
			tmp->y = y;
			tmp->z = ft_atoi(values[i]);
			++y;
			++i;
			tmp->next = (t_point *)malloc(sizeof(t_point));
			tmp = tmp->next;
			tmp->down = NULL;
            tmp->next = NULL;
			
		}
        if (x > 0)
        {
            if (n != y)
                return (clear_list(point));
        }
        n = y;
		++x;
		
	}
	tmp = NULL;
	return (connect_structure(point));
}
