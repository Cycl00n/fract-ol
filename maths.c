/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:46:10 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/06 16:49:59 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x_real = z1.x_real + z2.x_real;
	result.y_imaginary = z1.y_imaginary + z2.y_imaginary;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x_real = (z.x_real * z.x_real) - (z.y_imaginary * z.y_imaginary);
	result.y_imaginary = 2 * z.x_real * z.y_imaginary;
	return (result);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
