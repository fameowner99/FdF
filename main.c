/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:52:34 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/26 15:56:32 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_union	un;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
	{
		ft_putstr("Wrong input\n");
		return (0);
	}
	un.point = read_map(fd, &un.limit);
	close(fd);
	if (un.point)
	{
		un.color_on = 0;
		un.limit.curr_zoom = 1;
		un.mlx.init_ptr = mlx_init();
		un.mlx.window_ptr = mlx_new_window(un.mlx.init_ptr,
				SIZE_X, SIZE_Y, "FdF");
		un.img = ft_create_new_image(un);
		fdf(un);
	}
	else
		ft_putstr("invalid map\n");
	return (0);
}
