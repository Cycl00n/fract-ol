/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:52:10 by clnicola          #+#    #+#             */
/*   Updated: 2025/08/28 16:58:41 by clnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600

typedef struct s_image
{
	void	*img_ptr;
	char	*img_pxl_ptr;
	int		bits_pxl;
	int		endian;
	int		line_length;
}			t_image;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	image;
}			t_mlx_data;

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <sys/time.h>

#endif