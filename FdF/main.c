/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:52:34 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/14 18:19:10 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{


    t_mlx         obj;
	t_point		*point;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	point = read_map(fd);
	close(fd);
	if (point)
	{
        obj.mlx = mlx_init();
		obj.window = mlx_new_window(obj.mlx, 1000, 1000, "FdF");
        fdf(point, obj);
		mlx_loop(obj.mlx);
	}
	else
		ft_putstr("invalid map\n");
 	return (0);
}
