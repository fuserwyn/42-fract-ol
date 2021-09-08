/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:36:51 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/08/15 19:47:23 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/control.h"
#include "../libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_windows		*window;

	if (argc < 2)
		return (1);
	window = generate_windows(argc, argv);
	return (0);
}
