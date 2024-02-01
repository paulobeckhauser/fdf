/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/02 00:03:41 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	initialize_bresenham(t_coordinates iso_coord, int x2, int y2,
		t_bresenham *bres)
{
	bres->x1 = iso_coord.x;
	bres->y1 = iso_coord.y;
	bres->dx = abs(x2 - bres->x1);
	bres->dy = abs(y2 - bres->y1);
	bres->err = bres->dx - bres->dy;
	if (bres->x1 < x2)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (bres->y1 < y2)
		bres->sy = 1;
	else
		bres->sy = -1;
}

void	bresenham_algorithm(t_coordinates iso_coord, int x2, int y2, void *img)
{
	t_bresenham	bres;
	int			e2;

	initialize_bresenham(iso_coord, x2, y2, &bres);
	while (1)
	{
		my_mlx_pixel_put(img, bres.x1, bres.y1, 0x00FF0000);
		if (bres.x1 == x2 && bres.y1 == y2)
			break ;
		e2 = 2 * bres.err;
		if (e2 > -bres.dy)
		{
			bres.err -= bres.dy;
			bres.x1 += bres.sx;
		}
		if (e2 < bres.dx)
		{
			bres.err += bres.dx;
			bres.y1 += bres.sy;
		}
	}
}
