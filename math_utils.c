/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:29:01 by spitul            #+#    #+#             */
/*   Updated: 2024/04/07 16:56:45 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num -old_min)/(old_max - old_min)) + new_min;
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
