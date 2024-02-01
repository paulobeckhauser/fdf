/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 22:38:36 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}





void bresenham_algorithm(t_coordinates iso_coord, int x2, int y2, void *img)
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
	int	e2;

	int x1;
	int y1;

	x1 = iso_coord.x;
	y1 = iso_coord.y;
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
	{
		ft_printf("error!!!\n");
		ft_printf("1:(%d, %d), 2(%d, %d)\n", x1, y1, x2, y2);
	}
	if (x1 >= WINDOW_WITDH || x2 >= WINDOW_WITDH || y1 >= WINDOW_HEIGHT || y2 >= WINDOW_HEIGHT)
	{
		ft_printf("error!!!\n");
		ft_printf("1:(%d, %d), 2(%d, %d)\n", x1, y1, x2, y2);
	}
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	err = dx - dy;
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	while (1)
	{
		my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}


// void	bresenham_algorithm(int x1, int y1, int x2, int y2, void *img)
// {
// 	int	dx;
// 	int	dy;
// 	int	err;
// 	int	sx;
// 	int	sy;
// 	int	e2;

// 	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
// 	{
// 		printf("error!!!\n");
// 		printf("1:(%d, %d), 2(%d, %d)\n", x1, y1, x2, y2);
		
// 	}
// 	if (x1 >= WINDOW_WITDH || x2 >= WINDOW_WITDH || y1 >= WINDOW_HEIGHT || y2 >= WINDOW_HEIGHT)
// 	{
// 		printf("error!!!\n");
// 		printf("1:(%d, %d), 2(%d, %d)\n", x1, y1, x2, y2);
// 	}

// 	dx = abs(x2 - x1);
// 	dy = abs(y2 - y1);
// 	err = dx - dy;
// 	if (x1 < x2)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (y1 < y2)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	while (1)
// 	{
// 		my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
// 		if (x1 == x2 && y1 == y2)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x1 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y1 += sy;
// 		}
// 	}
// }
