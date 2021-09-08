/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:36:16 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 20:09:47 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/control.h"
#include "../libft/libft.h"
#include <stdio.h>

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	motion(int x, int y, t_windows *window)
{
	window->fractal->julia_k = init_complex(4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	draw_fractal(window);
	return (0);
}

int	zoomer(int wheel, int x, int y, t_windows *window)
{
	double	zoom;
	double	re;
	double	im;

	if (wheel == SCROLL_UP || wheel == SCROLL_DOWN)
	{
		if (wheel == SCROLL_UP)
			zoom = ZOOM_PLUS;
		else
			zoom = ZOOM_MINUS;
		re = window->fractal->re_min + x * window->fractal->calibration_re;
		im = window->fractal->im_min + y * window->fractal->calibration_im;
		window->fractal->re_min = re + (window->fractal->re_min - re) * zoom;
		window->fractal->im_min = im + (window->fractal->im_min - im) * zoom;
		window->fractal->re_max = re + (window->fractal->re_max - re) * zoom;
		window->fractal->im_max = im + (window->fractal->im_max - im) * zoom;
		draw_fractal(window);
	}
	return (0);
}

int	keyboard(int key, t_windows *window)
{
	t_fractals	*fractal;

	fractal = window->fractal;
	if (key == KEY_ESC)
		closer(key, window);
	else if (key == KEY_MINUS)
		fractal->max_iter = (int)(fractal->max_iter * 0.5);
	else if (key == KEY_PLUS)
		fractal->max_iter = (int)(fractal->max_iter * 2);
	else if (key == KEY_LEFT || key == KEY_DOWN
		|| key == KEY_RIGHT || key == KEY_UP)
		shifter(key, window);
	else if (key == KEY_C)
	{
		fractal->color += 1;
		fractal->color %= 4;
	}
	else
		return (key);
	draw_fractal(window);
	return (key);
}

void	shifter(int key, t_windows *window)
{
	double	shift;

	shift = (window->fractal->re_max
			- window->fractal->re_min) * SHIFT;
	if (key == KEY_LEFT)
	{
		window->fractal->re_min -= shift;
		window->fractal->re_max -= shift;
	}
	else if (key == KEY_RIGHT)
	{
		window->fractal->re_min += shift;
		window->fractal->re_max += shift;
	}
	else if (key == KEY_UP)
	{
		window->fractal->im_min += shift;
		window->fractal->im_max += shift;
	}
	else
	{
		window->fractal->im_min -= shift;
		window->fractal->im_max -= shift;
	}
}
