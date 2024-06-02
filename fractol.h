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
# include <X11/X.h>
# include <X11/keysym.h>
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
	int		endian;
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
	double	esc_val;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# define WIDTH 800
# define HEIGHT 800

void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
double	atod(char *s);

//double	map(double unscaled_num, double new_min, double factor);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

int	x_handle(t_fractal *fractal);
int key_handle(int keysym, t_fractal *fractal);
int	mouse_handle(int button, int x, int y, t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);

//# define DEFINITION 50 //hook member variable, important for the rendering speed
# define BLACK          0x000000
# define WHITE          0xFFFFFF
# define RED            0xFF0000
# define GREEN          0x00FF00
# define BLUE           0x0000FF
# define YELLOW         0xFFFF00
# define CYAN           0x00FFFF
# define MAGENTA        0xFF00FF
# define GRAY           0x808080
# define ORANGE         0xFFA500
# define PURPLE         0x800080
# define BROWN          0xA52A2A
# define PINK           0xFFC0CB

// Broken Colors
# define DARK_YELLOW    0x999900
# define LIGHT_CYAN     0x66FFFF
# define DARK_MAGENTA   0x990099
# define LIGHT_GRAY     0xD3D3D3

// Psychedelic Neon Colors
# define NEON_GREEN     0x39FF14
# define NEON_BLUE      0x14FFEC
# define NEON_PURPLE    0xE800E8
# define NEON_YELLOW    0xFFFF00
# define NEON_PINK      0xFF6EFF
# define NEON_ORANGE    0xFF9900

#endif