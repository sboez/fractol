/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 05:42:08 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 04:12:31 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_julia_x(t_img *e, int x, int y)
{
	double	za;
	double	zb;
	double	temp;
	int		i;

	za = ((4 * (float)x / WIN_X - 2) / e->zoom) + ((e->mouse_x / WIN_X));
	zb = ((-4 * (float)y / WIN_Y + 2) / e->zoom) + ((e->mouse_y / WIN_Y));
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->iteration)
	{
		temp = za;
		za = za * za - zb * zb + e->x0;
		zb = fabs(temp) * temp * zb + e->y0;
		i++;
	}
	return (i);
}

int		ft_batman(t_img *e, int x, int y)
{
	double	za;
	double	zb;
	double	temp;
	int		i;

	za = ((4 * (float)x / WIN_X - 2) / e->zoom) + ((e->mouse_x / WIN_X));
	zb = ((-4 * (float)y / WIN_Y + 2) / e->zoom) + ((e->mouse_y / WIN_Y));
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->iteration)
	{
		temp = za;
		za = za * za * za - zb * zb * za - (2 * za * zb * zb) + e->x0;
		zb = 2 * temp * temp * zb * zb + e->y0;
		i++;
	}
	return (i);
}

int		ft_square(t_img *e, int x, int y)
{
	int		i;

	i = 0;
	e->zoom = (e->zoom >= 5) ? 1.6 : e->zoom;
	e->zoom = (e->zoom <= 0.6) ? 1.6 : e->zoom;
	x = (x) / e->zoom;
	y = (y) / e->zoom;
	x = abs(x);
	y = abs(y);
	while ((x > 0 || y > 0) && i < e->iteration)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (145);
}
