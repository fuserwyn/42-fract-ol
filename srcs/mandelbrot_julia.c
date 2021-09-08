/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:37:00 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 18:43:03 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/control.h"
#include "../libft/libft.h"
#include <stdio.h>

double	mandelbrot(int *i, t_fractals *fractal)
{
	t_complex	z;
	double		z_re_pow;
	double		z_im_pow;

	*i = 0;
	z.re = fractal->mandelbrot_c.re;
	z.im = fractal->mandelbrot_c.im;
	z_re_pow = ft_pow(z.re, 2.0);
	z_im_pow = ft_pow(z.im, 2.0);
	while (ft_pow(z.re, 2.0) + ft_pow(z.im, 2.0) <= 4
		&& *i < fractal->max_iter)
	{
		z.im = (z.re + z.re) * z.im + fractal->mandelbrot_c.im;
		z.re = z_re_pow - z_im_pow + fractal->mandelbrot_c.re;
		z_re_pow = ft_pow(z.re, 2.0);
		z_im_pow = ft_pow(z.im, 2.0);
		(*i)++;
	}
	return (z_re_pow + z_im_pow);
}

double	julia(int *i, t_fractals *fractal)
{
	t_complex	z;
	double		z_re_pow;
	double		z_im_pow;

	*i = 0;
	z.re = fractal->mandelbrot_c.re;
	z.im = fractal->mandelbrot_c.im;
	z_re_pow = ft_pow(z.re, 2.0);
	z_im_pow = ft_pow(z.im, 2.0);
	while (ft_pow(z.re, 2.0) + ft_pow(z.im, 2.0) <= 4
		&& *i < fractal->max_iter)
	{
		z.im = (z.re + z.re) * z.im + fractal->julia_k.re;
		z.re = z_re_pow - z_im_pow + fractal->julia_k.im;
		z_re_pow = ft_pow(z.re, 2.0);
		z_im_pow = ft_pow(z.im, 2.0);
		(*i)++;
	}
	return (z_re_pow + z_im_pow);
}

double	mandelbar(int *i, t_fractals *fractal)
{
	t_complex	z;
	double		z_re_pow;
	double		z_im_pow;

	*i = 0;
	z.re = fractal->mandelbrot_c.re;
	z.im = fractal->mandelbrot_c.im;
	z_re_pow = ft_pow(z.re, 2.0);
	z_im_pow = ft_pow(z.im, 2.0);
	while (ft_pow(z.re, 2.0) + ft_pow(z.im, 2.0) <= 4
		&& *i < fractal->max_iter)
	{
		z.im = (-2 * z.re) * z.im + fractal->mandelbrot_c.im;
		z.re = z_re_pow - z_im_pow + fractal->mandelbrot_c.re;
		z_re_pow = ft_pow(z.re, 2.0);
		z_im_pow = ft_pow(z.im, 2.0);
		(*i)++;
	}
	return (z_re_pow + z_im_pow);
}
