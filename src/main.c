/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 05:47:04 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 04:32:22 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_display_opt(void)
{
	ft_putendl("\033[31mUsage: ./fractol [option number]\033[0m");
	ft_putstr("Make your choice :\n\
		1. Mandelbrot\n\
		2. Julia\n\
		3. Burning Ship\n\
		4. Square\n\
		5. X\n\
		6. Batman\n");
}

void	ft_usage(char **argv)
{
	ft_putendl("Keys :");
	ft_putendl("\t[ARROWS]\t-> Move");
	ft_putendl("\t[0]\t\t-> Iterations++");
	ft_putendl("\t[9]\t\t-> Iterations--");
	ft_putendl("\t[+]\t\t-> Zoom in");
	ft_putendl("\t[-]\t\t-> Zoom out");
	ft_putendl("\t[R]\t\t-> Reset values");
	ft_putendl("\t[SPACE]\t\t-> Colorize");
	ft_putendl("\t[ESC]\t\t-> Exit");
	ft_putendl("Mouse :");
	ft_putendl("\t[SCROLL]\t-> Zoom");
	ft_putendl("\t[RIGHT CLICK]\t-> Choose fractal");
	ft_putendl("\t[LEFT CLICK]\t-> Manipulate fractal");
	ft_putendl("\t[RED CROSS]\t-> Exit");
}

void	ft_get_opt(char q, t_img *e)
{
	(q == '1') ? e->fract = 1 : e->fract;
	(q == '2') ? e->fract = 2 : e->fract;
	(q == '3') ? e->fract = 3 : e->fract;
	(q == '4') ? e->fract = 4 : e->fract;
	(q == '5') ? e->fract = 5 : e->fract;
	(q == '6') ? e->fract = 6 : e->fract;
}

void	ft_mlx_main(t_img *e)
{
	ft_fractal_init(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fractol");
	ft_show_fractal(e->fract, e);
	mlx_hook(e->win, 2, 3, ft_key_hook, e);
	mlx_hook(e->win, 4, 3, ft_mouse, e);
	mlx_hook(e->win, 6, 3, ft_manipulate, e);
	mlx_hook(e->win, 17, 0, ft_red_cross, 0);
}

int		main(int argc, char **argv)
{
	t_img *e;

	if (argc != 2)
		ft_display_opt();
	else
	{
		if (!(e = (t_img*)malloc(sizeof(t_img))))
		{
			ft_putstr("Malloc Error -> e");
			exit(1);
		}
		ft_get_opt(argv[1][0], e);
		if (!(e->fract))
		{
			ft_display_opt();
			return (0);
		}
		ft_mlx_main(e);
		ft_usage(argv);
		mlx_loop(e->mlx);
	}
	return (0);
}
