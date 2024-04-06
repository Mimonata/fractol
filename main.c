/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:06:27 by spitul            #+#    #+#             */
/*   Updated: 2024/04/06 17:04:32 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
		{
			fractal.name = argv[1];
			//do the thing
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_connection);
		}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO); //tudu
		exit(EXIT_FAILURE);
	}
}