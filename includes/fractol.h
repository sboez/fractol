/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboez <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 05:47:24 by sboez             #+#    #+#             */
/*   Updated: 2017/09/15 05:28:50 by sboez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIN_X 800
# define WIN_Y 800
# define EXIT 53
# define LEFT_CLICK	1
# define RIGHT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define NUM_1 18
# define NUM_2 19
# define NUM_3 20
# define NUM_4 21
# define NUM_5 23
# define NUM_6 22
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP	126
# define COLOR 49
# define RESET 15
# define MORE_ITER 29
# define LESS_ITER 25

typedef struct	s_img
{
	int			bpp;
	int			sizeline;
	int			endian;
	void		*img;
	void		*win;
	void		*mlx;
	char		*data;
	double		zoom;
	double		start_x;
	double		start_y;
	float		mouse_x;
	float		mouse_y;
	int			iteration;
	int			state;
	int			red;
	int			green;
	int			blue;
	float		x0;
	float		y0;
	int			fract;
}				t_img;

int				ft_mandelbrot(t_img *e, int x, int y);
int				ft_julia(t_img *e, int x, int y);
int				ft_burning_ship(t_img *e, int x, int y);
int				ft_julia_x(t_img *e, int x, int y);
int				ft_batman(t_img *e, int x, int y);
int				ft_square(t_img *e, int x, int y);
int				ft_key_hook(int keycode, t_img *e);
void			ft_key_hook2(int keycode, t_img *e);
void			ft_fill_pixel(void *img, int x, int y, unsigned long color);
int				ft_what_fractal(t_img *e);
void			ft_fractal_init(t_img *e);
void			ft_show_fractal(int frac, t_img *e);
int				ft_manipulate(int x, int y, t_img *e);
void			ft_manipulate2(int x, int y, t_img *e);
int				ft_mouse(int keycode, int x, int y, t_img *e);
void			ft_mouse2(int keycode, int x, int y, t_img *e);
int				ft_red_cross(void);
void			ft_display_opt(void);
void			ft_usage(char **argv);
void			ft_get_opt(char q, t_img *e);
void			ft_mlx_main(t_img *e);
int				main(int argc, char **argv);
void			ft_tools(t_img *e, int y);

#endif
