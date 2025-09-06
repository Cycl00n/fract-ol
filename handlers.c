/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:08 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/06 17:03:58 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
		fractal->zoom *= 0.9;
	if (button == 5)
		fractal->zoom *= 1.1;
	render_fract(fractal);
	return (0);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_window(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_KP_Add || keysym == XK_plus || keysym == XK_Page_Up)
		fractal->precision += 10;
	else if (keysym == XK_KP_Subtract || keysym == XK_minus
		|| keysym == XK_Page_Down)
		fractal->precision -= 10;
	render_fract(fractal);
	return (0);
}
