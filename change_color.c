/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:09:51 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/24 15:01:20 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		from_hex_to_dec(char *hex, int power, int dec)
{
	int			i;
	int			j;
	int			m;
	char		*hex_digits;

	hex_digits = "0123456789ABCDEFabcdef";
	i = (int)ft_strlen(hex) - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < 22)
		{
			if (hex[i] == hex_digits[j])
			{
				m = 0;
				(j > 15) ? m = -6 : 0;
				dec += (j + m) * pow(16, power);
			}
			++j;
		}
		--i;
		++power;
	}
	return (dec);
}

int				check_color(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		return (from_hex_to_dec(str + 2, 0, 0));
	else if (str[i] >= '0' && str[i] <= '9')
		return (ft_atoi(str));
	return (0);
}

int				my_colors(t_point p1, t_point p2)
{
	if (p1.start_z != p2.start_z && p1.start_z > 0 && p2.start_z > 0)
		return (0xCC0000);
	if (p1.start_z != p2.start_z && p1.start_z < 0 && p2.start_z < 0)
		return (0x0000FF);
	if (p1.start_z == 0 && p2.start_z == 0)
		return (0x66FFCC);
	if (p1.start_z == p2.start_z && p1.start_z != 0)
		return (0x99FF33);
	return (0x0000FF);
}
