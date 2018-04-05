/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 05:46:55 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 04:38:14 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_key_hook(int keycode, t_img *e)
{
	if (keycode == EXIT)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == COLOR)
	{
		e->red -= 5;
		e->blue -= 15;
		e->green -= 10;
	}
	(keycode == UP) ? e->mouse_y -= 50 / e->zoom : e->mouse_y;
	(keycode == DOWN) ? e->mouse_y += 50 / e->zoom : e->mouse_y;
	(keycode == LEFT) ? e->mouse_x += 50 / e->zoom : e->mouse_x;
	(keycode == RIGHT) ? e->mouse_x -= 50 / e->zoom : e->mouse_x;
	(keycode == MORE_ITER) ? e->iteration += 1 : e->iteration;
	(keycode == LESS_ITER) ? e->iteration -= 1 : e->iteration;
	(keycode == ZOOM_IN) ? e->zoom *= 1.1 : e->zoom;
	(keycode == ZOOM_OUT) ? e->zoom /= 1.1 : e->zoom;
	ft_key_hook2(keycode, e);
	ft_show_fractal(e->state, e);
	return (0);
}

void	ft_key_hook2(int keycode, t_img *e)
{
	if (keycode == NUM_1 || keycode == NUM_2 || keycode == NUM_3
			|| keycode == NUM_4 || keycode == NUM_5 ||
			keycode == NUM_6 || keycode == RESET)
		ft_fractal_init(e);
	(keycode == NUM_1) ? e->fract = 1 : e->fract;
	(keycode == NUM_2) ? e->fract = 2 : e->fract;
	(keycode == NUM_3) ? e->fract = 3 : e->fract;
	(keycode == NUM_4) ? e->fract = 4 : e->fract;
	(keycode == NUM_5) ? e->fract = 5 : e->fract;
	(keycode == NUM_6) ? e->fract = 6 : e->fract;
	(e->fract == 1 && keycode == RESET) ? e->fract = 1 : e->fract;
	(e->fract == 2 && keycode == RESET) ? e->fract = 2 : e->fract;
	(e->fract == 3 && keycode == RESET) ? e->fract = 3 : e->fract;
	(e->fract == 4 && keycode == RESET) ? e->fract = 4 : e->fract;
	(e->fract == 5 && keycode == RESET) ? e->fract = 5 : e->fract;
	(e->fract == 6 && keycode == RESET) ? e->fract = 6 : e->fract;
}
