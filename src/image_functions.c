/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:49:22 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/29 12:05:23 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
						&img.line_length, &img.endian);
	
	my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	my_mlx_pixel_put(&img, 501, 501, 0x00FF0000);
	my_mlx_pixel_put(&img, 502, 502, 0x00FF0000);
	my_mlx_pixel_put(&img, 503, 503, 0x00FF0000);
	my_mlx_pixel_put(&img, 504, 504, 0x00FF0000);
	my_mlx_pixel_put(&img, 505, 505, 0x00FF0000);
	my_mlx_pixel_put(&img, 506, 506, 0x00FF0000);
	my_mlx_pixel_put(&img, 507, 507, 0x00FF0000);
	my_mlx_pixel_put(&img, 508, 508, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}