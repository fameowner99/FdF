/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:55:50 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 15:23:58 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putpixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
		*(int *)(img->image_ptr + ((x + y * SIZE_X) * img->bpp)) = color;
}

t_img		*ft_create_new_image(t_union un)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->new_image = mlx_new_image(un.mlx.init_ptr, SIZE_X, SIZE_Y);
	img->image_ptr = mlx_get_data_addr(img->new_image,
			&img->bpp, &img->size_line, &img->endian);
	img->bpp /= 8;
	return (img);
}

void		ft_clear_image(t_img *img)
{
	ft_bzero(img->image_ptr, (size_t)SIZE_X * SIZE_Y * img->bpp);
}
