/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:29:01 by spitul            #+#    #+#             */
/*   Updated: 2024/04/18 18:10:52 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double factor)
{
	return (new_min + unscaled_num * factor);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z2.y + z2.y;
	return (res);
}

t_complex	sqaure_complex(t_complex z)
{
	t_complex	res;

	res.x = z.x * z.x - z.y * z.y;
	res.y = 2 * z.x * z.y;
	return (res);
}
