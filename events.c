/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:58:08 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/03 15:06:46 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom(t_fractal *fractal, double zoom, int mouse_x, int mouse_y)
{
	
}

int mouse_press(int button,int x, int y, t_fractal *fractal)
{
		if (button == 4)
		zoom(fractal, 0.9, x, y);
	else if (button == 5)
		zoom(fractal, 1.1, x, y);
}