/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:55:12 by spitul            #+#    #+#             */
/*   Updated: 2024/04/06 18:37:12 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_img
{
	void	*img_ptr; //ptr  image struct
	char	*pixels_ptr; //points actual pixels
	int		bpp; //bits per pix
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection;
	void	*mlx_window;
	//Image
	t_img	img;
	//Hooks member var
}				t_fractal;

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define WIDTH 800
# define HEIGHT 800

void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

void	fractal_init(t_fractal *fractal);

#endif