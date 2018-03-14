/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:49:50 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/14 18:36:21 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "minilibx_macos/mlx.h"
# include <stdio.h> // delete
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	struct s_point	*next;
    struct s_point  *down;
}					t_point;

typedef struct      s_mlx
{
    void            *mlx;
    void            *window;
}                   t_mlx;

void	draw_line(t_point p1, t_point p2, t_mlx obj, int colour);

t_point		*read_map(int fd);

void		fdf(t_point *point, t_mlx obj);

void		connect_lines(t_point *point, t_mlx obj);

#endif
