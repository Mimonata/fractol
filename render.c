/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:19:18 by spitul            #+#    #+#             */
/*   Updated: 2024/04/18 18:09:36 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		re_factor;
	double		im_factor;

	z.x = 0;
	z.y = 0;
	re_factor = 4 / (WIDTH - 1);
	im_factor = 4 / (HEIGHT - 1); 
	c.x = map(x, -2, re_factor);
	c.y = map(y, 2, im_factor);
	while()
	{
		z = square_complex(square_complex(z), c);
		if ()
		{
			
		}
	}
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++ y < HEIGHT)
	{
		x = -1;
		while (++ x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}
