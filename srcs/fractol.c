/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:36:39 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/16 20:00:40 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/control.h"
#include "../libft/libft.h"
#include <stdio.h>

t_fractals	*generate_fractal(int argc, char *argv[])
{
	t_fractals	*fractal;

	fractal = (t_fractals *)malloc(sizeof(t_fractals));
	if (fractal == NULL)
		return (NULL);
	select_fractal(fractal, argc, argv);
	fractal->re_min = RE_MIN;
	fractal->im_min = IM_MIN;
	fractal->re_max = RE_MAX;
	fractal->im_max = IM_MAX;
	fractal->max_iter = ITERATION;
	fractal->color = 0;
	return (fractal);
}

void	select_fractal(t_fractals *fractal, int argc, char *argv[])
{
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->name = JULIA;
		if (argc == 2)
		{
			fractal->julia_k.re = 0.4;
			fractal->julia_k.im = -0.2;
		}
		else if (argc == 4)
		{
			fractal->julia_k.re = ft_atof(argv[2]);
			fractal->julia_k.im = ft_atof(argv[3]);
		}
		else
			ft_error(-1);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->name = MANDELBROT;
	else if (ft_strcmp(argv[1], "mandelbar") == 0)
		fractal->name = MANDELBAR;
	else
		ft_error(-1);
}

void	draw_fractal(t_windows *window)
{
	t_fractals	*new_fractal;
	double		re;
	double		im;

	re = 0.0;
	im = 0.0;
	new_fractal = window->fractal;
	new_fractal->calibration_re = (new_fractal->re_max
			- new_fractal->re_min) / WIDTH;
	new_fractal->calibration_im = (new_fractal->im_max
			- new_fractal->im_min) / HEIGHT;
	part_of_draw_fractal (window, re, im);
	mlx_put_image_to_window(window->mlx,
		window->window, window->data_image->img, 0, 0);
	string_navigation(window);
}

void	part_of_draw_fractal(t_windows *window, int x, int y)
{
	int			i;
	double		current_fractal_value;
	t_fractals	*new_fractal;
	double		fractal_colour;

	new_fractal = window->fractal;
	y = 0;
	while (y < HEIGHT)
	{
		new_fractal->mandelbrot_c.im = new_fractal->im_min
			+ y * new_fractal->calibration_im;
		x = 0;
		while (x < WIDTH)
		{
			new_fractal->mandelbrot_c.re = new_fractal->re_min
				+ x * new_fractal->calibration_re;
			current_fractal_value = fractal_name(&i, new_fractal);
			fractal_colour = ft_paint(current_fractal_value, i, new_fractal);
			my_mlx_pixel_put(window->data_image, x, y,
				ft_paint(current_fractal_value, i, new_fractal));
			x++;
		}
		y++;
	}
}
