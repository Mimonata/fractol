/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:19:18 by spitul            #+#    #+#             */
/*   Updated: 2024/04/06 18:41:25 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0;
	z.y = 0;
	c.x = map(x, -2, 2, 0, WIDTH);
	c.y = map(y, 2, -2, 0, HEIGHT);
	while()
	{
		
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