/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 07:34:23 by spitul            #+#    #+#             */
/*   Updated: 2024/06/01 17:07:17 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	x_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free (fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		x_handle(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom); 
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations += 10; 
	else if (keysym == XK_minus)
		fractal->iterations -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5) //zooms in
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	int	re_factor;
	int	im_factor;
	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		//re_factor = 4 / (WIDTH - 1);
		//im_factor = -4 / (HEIGHT - 1); 
		fractal->julia_x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	}
	fractal_render(fractal);
	return (0);
}
