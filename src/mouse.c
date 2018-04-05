/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 02:47:36 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 04:39:32 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_manipulate(int x, int y, t_img *e)
{
	if (e->state == 1 && (x > 0 && y > 0) && (x < WIN_X && y < WIN_Y))
	{
		if (e->fract == 1)
		{
			e->mouse_x = x + 50 / e->zoom;
			e->mouse_y = y + 50 / e->zoom;
			ft_show_fractal(e->fract, e);
		}
		if (e->fract == 2)
		{
			x -= WIN_X / 2;
			y -= WIN_Y / 2;
			e->x0 = ((float)x / WIN_X) * 2;
			e->y0 = ((float)y / WIN_Y) * 2;
			ft_show_fractal(e->fract, e);
		}
		if (e->fract == 3)
		{
			e->mouse_x = x + 50 / e->zoom;
			e->mouse_y = y + 50 / e->zoom;
			ft_show_fractal(e->fract, e);
		}
		ft_manipulate2(x, y, e);
	}
	return (0);
}

void	ft_manipulate2(int x, int y, t_img *e)
{
	if (e->fract == 5)
	{
		x -= WIN_X / 2;
		y -= WIN_Y / 2;
		e->x0 = ((float)x / WIN_X) * 2;
		e->y0 = ((float)y / WIN_Y) * 2;
		ft_show_fractal(e->fract, e);
	}
	if (e->fract == 6)
	{
		x -= WIN_X / 2;
		y -= WIN_Y / 2;
		e->x0 = ((float)x / WIN_X) * 2;
		e->y0 = ((float)y / WIN_Y) * 2;
		ft_show_fractal(e->fract, e);
	}
}

int		ft_mouse(int keycode, int x, int y, t_img *e)
{
	int px;
	int py;

	px = x;
	py = y;
	ft_mouse2(keycode, x, y, e);
	x -= WIN_X / 2;
	y -= WIN_Y / 2;
	if (keycode == SCROLL_UP)
	{
		e->zoom *= 1.1;
		e->iteration += 1;
		e->mouse_x += x / e->zoom / 2.51;
		e->mouse_y -= y / e->zoom / 2.51;
	}
	if (keycode == SCROLL_DOWN & e->zoom > 0.1)
	{
		e->zoom /= 1.1;
		(e->zoom < 0.1) ? e->zoom = 0.1 : e->zoom;
		(e->iteration > 15) ? e->iteration -= 1 : e->iteration;
	}
	if (keycode)
		ft_show_fractal(e->fract, e);
	return (0);
}

void	ft_mouse2(int keycode, int x, int y, t_img *e)
{
	int px;
	int py;

	px = x;
	py = y;
	if (keycode == RIGHT_CLICK)
	{
		if (e->state == 1)
			e->state = 0;
		else
			e->state = 1;
	}
	if (keycode == LEFT_CLICK && py >= 765 && py <= 790)
	{
		if (px >= 10 && px <= 550)
			ft_fractal_init(e);
		(px >= 10 && px <= 100) ? e->fract = 1 : e->fract;
		(px >= 140 && px <= 200) ? e->fract = 2 : e->fract;
		(px >= 210 && px <= 340) ? e->fract = 3 : e->fract;
		(px >= 360 && px <= 450) ? e->fract = 4 : e->fract;
		(px >= 460 && px <= 490) ? e->fract = 5 : e->fract;
		(px >= 500 && px <= 550) ? e->fract = 6 : e->fract;
	}
}

int		ft_red_cross(void)
{
	exit(0);
}
