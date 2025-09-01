/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:46:10 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/01 19:15:32 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
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
