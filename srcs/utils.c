/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:37:09 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:57:50 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/control.h"
#include "../libft/libft.h"
#include <stdio.h>

void	ft_error(int error)
{
	if (error > 0)
	{
		perror(NULL);
	}
	if (error == ERROR)
	{
		printf("Error: ./fractol \"fractal_name\" \"re\" \"im\"\n");
		printf("\"fractal_names\":\n");
		printf("\tmandelbrot\n");
		printf("\tjulia\n");
		printf("\tmandelbar\n");
		exit(error);
	}
}

int	closer(int key, t_windows *window)
{
	exit(0);
	(void)window;
	return (key);
}

double	fractal_name(int *i, t_fractals *fractal)
{
	if (fractal->name == MANDELBROT)
	{
		return (mandelbrot(i, fractal));
	}
	else if (fractal->name == JULIA)
	{
		return (julia(i, fractal));
	}
	else if (fractal->name == MANDELBAR)
	{
		return (mandelbar(i, fractal));
	}
	else
		return (0.0);
}

void	string_navigation(t_windows *navigation)
{
	mlx_string_put(navigation->mlx, navigation->window, 800, 40, 0xFFFFFF,
		"-------------ZOOM------------");
	mlx_string_put(navigation->mlx, navigation->window, 800, 70, 0xf7f070,
		"       Scroll UP | Scroll DOWN         ");
	mlx_string_put(navigation->mlx, navigation->window, 800, 110, 0xFFFFFF,
		"-------------MOVE------------");
	mlx_string_put(navigation->mlx, navigation->window, 800, 140, 0xf7f070,
		"        Arrow UP | Arrow DOWN    ");
	mlx_string_put(navigation->mlx, navigation->window, 800, 180, 0xf7f070,
		"     Arrow RIGHT | Arrow LIFT ");
	mlx_string_put(navigation->mlx, navigation->window, 800, 220, 0xFFFFFF,
		"--------CHANGE COLOR--------");
	mlx_string_put(navigation->mlx, navigation->window, 800, 250, 0xf7f070,
		"           BUTTON (C) ");
	mlx_string_put(navigation->mlx, navigation->window, 800, 280, 0xFFFFFF,
		"-------------EXIT-----------");
	mlx_string_put(navigation->mlx, navigation->window, 800, 310, 0xf7f070,
		"           BUTTON (ESC) ");
	mlx_string_put(navigation->mlx, navigation->window, 800, 340, 0xFFFFFF,
		"-----------ITERATION--------");
	mlx_string_put(navigation->mlx, navigation->window, 800, 370, 0xf7f070,
		"           PLUS | MINUS     ");
}
