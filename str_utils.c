/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:45:06 by spitul            #+#    #+#             */
/*   Updated: 2024/04/06 16:45:16 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	n;

	n = 0;
	while (s[n])
		n ++;
	write(fd, s, n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL || !n)
		return (0);
	while ((i < (n - 1) && (s1[i] != '\0') && 
			(s2[i] != '\0') && (s1[i] == s2[i])))
		i ++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

double	atod(char *s)
{
	long double	c;
	double		fract_n;
	double		power;
	int			sign;

	sign = 1;
	power = 1;
	c = 0;
	fract_n = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s ++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s ++;
	}
	while (*s != '.' && (*s >= 48 && *s <= 57) && *s)
		c = c * 10 + (*s++ - 48);
	if (*s == '.')
		s ++;
	while ((*s >= 48 && *s <= 57) && *s)
	{
		power /= 10;
		fract_n = fract_n + (*s++ - 48) * power;
	}
	return ((c + fract_n) * sign);
}

/*int	main(void)
{
	ft_putstr_fd("does it work with \n\n", 1);
	return (0);
}*/