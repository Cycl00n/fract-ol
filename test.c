/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:50:55 by clnicola          #+#    #+#             */
/*   Updated: 2025/08/28 18:10:48 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_pxl / 8));
	*((unsigned int *)(offset + img->img_pxl_ptr)) = color;
}

void	color_screen(t_mlx_data *data, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if(i%5 == 0)
				ft_pixel_put(&data->image, i, j, color);
			i++;
		}
		j++;
	}
}

int	handle_key(int keysym, t_mlx_data *data)
{
	int	witdh;
	int	height;

	witdh = WIDTH;
	height = HEIGHT;
	if (keysym == XK_Escape)
	{
		ft_printf("The (ESC) key has been pressed\n");
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else if (keysym == XK_r)
		color_screen(data, 0xFF0000);
	else if (keysym == XK_g)
		color_screen(data, 0x00FF00);
	else if (keysym == XK_b)
		color_screen(data, 0x0000FF);
	else
		printf("They %d key has been pressed\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr,data->mlx_win,data->image.img_ptr,0,0);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	data.image.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.image.img_pxl_ptr = mlx_get_data_addr(data.image.img_ptr,
			&data.image.bits_pxl, &data.image.line_length, &data.image.endian);
	mlx_key_hook(data.mlx_win, handle_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
