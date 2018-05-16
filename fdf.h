/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:49:50 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 20:01:41 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define SIZE_X 1500
# define SIZE_Y 1500

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			start_z;
	int				b;
	int				color;
	struct s_point	*next;
	struct s_point	*down;
}					t_point;

typedef struct		s_img
{
	void			*new_image;
	void			*image_ptr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*init_ptr;
	void			*window_ptr;
}					t_mlx;

typedef struct		s_limit
{
	double			curr_zoom;
	double			zoom;
	double			move_x;
	double			move_y;
	double			max_x;
	double			max_y;
	double			min_z;
	double			max_z;
}					t_limit;

typedef struct		s_union
{
	t_img			*img;
	t_mlx			mlx;
	t_point			*point;
	t_limit			limit;
	int				color_on;
}					t_union;

typedef struct		s_draw
{
	double			dx;
	double			dy;
	double			error;
	double			derror;
	int				b;
	double			x;
	double			y;
}					t_draw;

typedef struct		s_read
{
	double			n;
	double			x;
	double			y;
	int				i;
}					t_read;

int					my_colors(t_point p1, t_point p2);

int					check_color(char *str);

void				draw_line(t_point p1, t_point p2, t_union un);

t_point				*read_map(int fd, t_limit *limit);

void				fdf(t_union un);

void				connect_lines(t_union un);

void				ft_putpixel(t_img *img, int x, int y, int color);

t_img				*ft_create_new_image(t_union un);

void				ft_clear_image(t_img *img);

void				translate_map(t_union *un, int key);

void				zoom(t_union *un, int key);

void				rotate(t_union un, int key);

t_point				*new_node(t_point *tmp);

t_point				*set_start_values(t_point *point, t_limit *limit);

void				fill_xyz(t_read *read, t_point **tmp, char **values);

#endif
