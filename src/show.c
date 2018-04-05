/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 02:50:09 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 06:32:38 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fill_pixel(void *img, int x, int y, unsigned long color)
{
	t_img	pic;
	int		i;

	pic.data = mlx_get_data_addr(img, &pic.bpp, &pic.sizeline, &pic.endian);
	i = x * 4 + y * pic.sizeline;
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
	{
		pic.data[i] = color % 256;
		color /= 256;
		pic.data[i + 1] = color % 256;
		color /= 256;
		pic.data[i + 2] = color % 256;
		color /= 256;
		pic.data[i + 3] = 0;
		color /= 256;
	}
}

void	ft_tools(t_img *e, int y)
{
	int x;
	int	rcol;
	int color;

	x = 0;
	rcol = 0;
	color = 0x000000;
	while (x < WIN_X)
	{
		(e->fract == 1) ? rcol = ft_mandelbrot(e, x, y) : rcol;
		(e->fract == 2) ? rcol = ft_julia(e, x, y) : rcol;
		(e->fract == 3) ? rcol = ft_burning_ship(e, x, y) : rcol;
		(e->fract == 4) ? rcol = ft_square(e, x, y) : rcol;
		(e->fract == 5) ? rcol = ft_julia_x(e, x, y) : rcol;
		(e->fract == 6) ? rcol = ft_batman(e, x, y) : rcol;
		color = ((255 - rcol * e->red) << 16) +
			((255 - rcol * e->green) << 8) + (255 - rcol * e->blue);
		if (rcol != e->iteration)
			ft_fill_pixel(e->img, x, y, color);
		x++;
	}
}

int		ft_what_fractal(t_img *e)
{
	int y;

	y = 0;
	while (y < WIN_Y)
	{
		ft_tools(e, y);
		y++;
	}
	return (0);
}

void	ft_fractal_init(t_img *e)
{
	e->start_x = 0;
	e->start_y = 0;
	e->zoom = 1;
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->iteration = 20;
	e->red = 3;
	e->green = 6;
	e->blue = 1;
}

void	ft_show_fractal(int frac, t_img *e)
{
	int		y;
	char	*s;

	s = NULL;
	y = 580;
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_what_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	mlx_string_put(e->mlx, e->win, 10, 10, 0x90A4AE, "iterations :");
	s = ft_itoa(e->iteration);
	mlx_string_put(e->mlx, e->win, 135, 10, 0x90A4AE, s);
	ft_strdel(&s);
	s = ft_itoa(e->zoom);
	mlx_string_put(e->mlx, e->win, 80, 30, 0x90A4AE, s);
	ft_strdel(&s);
	mlx_string_put(e->mlx, e->win, 10, 30, 0x90A4AE, "zoom :");
	if (e->state == 1)
		mlx_string_put(e->mlx, e->win, 10, 50, 0x90A4AE, "Left Click On");
	mlx_string_put(e->mlx, e->win, 10, 770, 0x90A4AE, "Mandelbrot");
	mlx_string_put(e->mlx, e->win, 135, 770, 0x90A4AE, "Julia");
	mlx_string_put(e->mlx, e->win, 210, 770, 0x90A4AE, "Burningship");
	mlx_string_put(e->mlx, e->win, 360, 770, 0x90A4AE, "Square");
	mlx_string_put(e->mlx, e->win, 460, 770, 0x90A4AE, "X");
	mlx_string_put(e->mlx, e->win, 500, 770, 0x90A4AE, "Batman");
}
