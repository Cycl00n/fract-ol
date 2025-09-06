/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:04:11 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/06 17:23:26 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_pxl / 8));
	*(unsigned int *)(offset + img->img_pxl_ptr) = color;
}

void	mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x_real = fractal->julia_x;
		c->y_imaginary = fractal->julia_y;
	}
	else
	{
		c->x_real = z->x_real;
		c->y_imaginary = z->y_imaginary;
	}
}

void	render_fract(t_fractal *fractal)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			is_in_set(i, j, fractal);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win,
		fractal->image.img_ptr, 0, 0);
}

void	is_in_set(int x, int y, t_fractal *fractal)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x_real = map(x, -2, +2, WIDTH) * fractal->zoom + fractal->shift_x;
	z.y_imaginary = map(y, +2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
	mandel_julia(&z, &c, fractal);
	while (i < fractal->precision)
	{
		z = add_complex(square_complex(z), c);
		if ((z.x_real * z.x_real) + (z.y_imaginary
				* z.y_imaginary) > fractal->escape)
		{
			color = map(i, BLACK, WHITE, fractal->precision);
			ft_pixel_put(&fractal->image, x, y, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(&fractal->image, x, y, CYAN_AQUA);
}
