/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:32:19 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/01 19:02:03 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape = 4;
	fractal->precision = 42;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		return ;
	fractal->mlx_win = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		return ;
	}
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	fractal->image.img_pxl_ptr = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits_pxl, &fractal->image.line_length,
			&fractal->image.endian);
	//event_init();
	data_init(fractal);
}
