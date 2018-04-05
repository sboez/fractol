/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 05:41:55 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 04:30:49 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_mandelbrot(t_img *e, int x, int y)
{
	int		i;
	double	za;
	double	zb;
	double	tmp;

	e->x0 = 1.5 * (x - WIN_X / 2) / (0.5 * e->zoom * WIN_X)\
		+ (e->mouse_x / WIN_X / 1.37) - 0.5;
	e->y0 = (y - WIN_Y / 2) / (0.5 * e->zoom * WIN_Y)\
		- (e->mouse_y / WIN_Y / 1.92);
	za = 0;
	zb = 0;
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->iteration)
	{
		tmp = za;
		za = tmp * tmp - zb * zb + e->x0;
		zb = 2 * tmp * zb + e->y0;
		i++;
	}
	return (i);
}

int		ft_julia(t_img *e, int x, int y)
{
	double	za;
	double	zb;
	double	tmp;
	int		i;

	za = ((4 * (float)x / WIN_X - 2) / e->zoom) + ((e->mouse_x / WIN_X));
	zb = ((-4 * (float)y / WIN_Y + 2) / e->zoom) + ((e->mouse_y / WIN_Y));
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->iteration)
	{
		tmp = za;
		za = za * za - zb * zb + e->x0;
		zb = 2 * tmp * zb + e->y0;
		i++;
	}
	return (i);
}

int		ft_burning_ship(t_img *e, int x, int y)
{
	int		i;
	double	za;
	double	zb;
	double	tmp;

	e->x0 = 1.5 * (x - WIN_X / 2) / (0.5 * e->zoom * WIN_X)
		+ (e->mouse_x / WIN_X / 1.30) - 0.5;
	e->y0 = (y - WIN_Y / 2) / (0.5 * e->zoom * WIN_Y)
		- (e->mouse_y / WIN_Y / 1.97);
	za = 0;
	zb = 0;
	i = 0;
	while (za * za + zb * zb <= 4 && i < e->iteration)
	{
		tmp = za;
		za = fabs(tmp * tmp) - zb * zb + e->x0;
		zb = 2 * fabs(tmp * zb) + e->y0;
		i++;
	}
	return (i);
}
