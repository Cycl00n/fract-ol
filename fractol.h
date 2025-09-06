/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:52:10 by clnicola          #+#    #+#             */
/*   Updated: 2025/09/06 17:06:00 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <sys/time.h>

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define NEON_PINK 0xFF6EC7
# define ELECTRIC_BLUE 0x7DF9FF
# define LIME_GREEN 0x32FF00
# define ACID_YELLOW 0xFFFF31
# define VIVID_ORANGE 0xFF5F1F
# define ULTRA_VIOLET 0x6F00FF
# define HOT_MAGENTA 0xFF1DCE
# define CYAN_AQUA 0x00FFFF
# define PSY_RED 0xFF073A
# define TRIPPY_PURPLE 0xBF00FF

typedef struct s_complex
{
	double	x_real;
	double	y_imaginary;
}			t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_pxl_ptr;
	int		bits_pxl;
	int		endian;
	int		line_length;
}			t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_win;
	t_image	image;
	double	escape;
	int		precision;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

void		ft_pixel_put(t_image *img, int x, int y, int color);
t_complex	square_complex(t_complex z);
t_complex	add_complex(t_complex z1, t_complex z2);
void		ft_pixel_put(t_image *img, int x, int y, int color);
void		render_fract(t_fractal *fractal);
void		is_in_set(int x, int y, t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		is_in_set(int i, int j, t_fractal *fractal);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
int			key_handle(int keysym, t_fractal *fractal);
void		event_init(t_fractal *fractal);
int			close_window(t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);
void		mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal);

#endif