/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:34:53 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/16 20:56:17 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/control.h"
#include "../libft/libft.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data_image *image_pixel, int x, int y, int color)
{
	char	*dst;

	dst = image_pixel->addr + (y * image_pixel->line_length
			+ x * (image_pixel->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data_image	*generate_pixels(void *mlx)
{
	t_data_image	*data_image;

	data_image = (t_data_image *)malloc(sizeof(t_data_image));
	if (data_image == NULL)
		return (NULL);
	data_image->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data_image->addr = mlx_get_data_addr(data_image->img,
			&data_image->bits_per_pixel, &data_image->line_length,
			 &data_image->endian);
	if (data_image->addr == NULL)
		return (NULL);
	return (data_image);
}

t_windows	*generate_windows(int argc, char *argv[])
{
	t_windows	*windows;

	windows = (t_windows *)malloc(sizeof(t_windows));
	if (windows == NULL)
		return (NULL);
	windows->mlx = mlx_init();
	if (windows->mlx == NULL)
		return (NULL);
	windows->window = mlx_new_window(windows->mlx,
			1100, HEIGHT, "FRACTAL");
	if (windows->window == NULL)
		return (NULL);
	windows->data_image = generate_pixels(windows->mlx);
	windows->fractal = generate_fractal(argc, argv);
	hooks(windows, argv);
	draw_fractal(windows);
	mlx_loop(windows->mlx);
	return (windows);
}

void	hooks(t_windows *windows, char *argv[])
{
	mlx_hook(windows->window,
		 KEY_PRESS, MASK_KEY_PRESS, keyboard, windows);
	mlx_hook(windows->window,
		 DESTROY, MASK_DESTROY, closer, windows);
	mlx_hook(windows->window,
		 WHEEL, MASK_WHEEL, zoomer, windows);
	if (ft_strcmp(argv[1], "julia") == 0)
		mlx_hook(windows->window, MOTION_NOTIFY,
			MASK_POINTER_MOTION, motion, windows);
}

int	ft_paint(double r, int i, t_fractals *fractal)
{
	int		option;
	double	t;

	t = (double)i / (double)(fractal->max_iter);
	option = fractal->color;
	if (option == 0)
		return ((int)(COLOR - (i == fractal->max_iter) * COLOR));
	else if (option == 1)
		return ((int)(i * COLOR) & 0x00aefdaf);
	else if (option == 2)
		return (((int)(9 * t * t * 255)) << 16
			| ((int)(7 * (1 - t) * t * 255)) << 8
			| ((int)(3 * (1 - t) * (1 - t) * 255)));
	else if (option == 3)
		return ((int)(9 * (1 - t) * ft_pow(t, 3) * 255) << 16
			| (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8
			| (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255));
	else
		return (r);
}
