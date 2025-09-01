/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:50:55 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/01 19:15:58 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(1);
	return (0);
}


int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		render_fract(&fractal);
		//mlx_key_hook(fractal.mlx_win, handle_key, &fractal);
		mlx_hook(fractal.mlx_win, 17, 0, close_window, &fractal);
		mlx_loop(fractal.mlx_connection);
	}
	return (0);
}
