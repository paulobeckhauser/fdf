/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/28 14:26:04 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"
# include <stdio.h>

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	apply_algo(int x1, int y1, int x2, int y2, void *mlx_connection, void *mlx_window)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	while (x <= x2)
	{
		// printf("(%d, %d)\n", x, y);
        mlx_pixel_put(mlx_connection, mlx_window, x, y, 0xff0000);
		x++;
		if (p < 0)
		{
			p = p + 2 * dy;
		}
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
	}
}

void	bresenham_algorithm(int x1, int y1, int x2, int y2, void *mlx_connection, void *mlx_window)
{
	if (x1 > x2)
	{
		swap_int(&x1, &x2);
		swap_int(&y1, &y2);
	}
	if (x1 == x2)
	{
		if (y1 > y2)
			swap_int(&y1, &y2);
		while (y1 <= y2)
		{
			// printf("(%d, %d)\n", x1, y1);
            mlx_pixel_put(mlx_connection, mlx_window, x1, y1, 0xff0000);
			y1++;
		}
	}
	else if (y1 == y2)
	{
		while (x1 <= x2)
		{
			// printf("(%d, %d)\n", x1, y1);
            mlx_pixel_put(mlx_connection, mlx_window, x1, y1, 0xff0000);
			x1++;
		}
	}
	else
		apply_algo(x1, y1, x2, y2, mlx_connection, mlx_window);
}

// The use of the images of the MiniLibX is mandatory.

int main(void)
{
	void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init();

    mlx_window = mlx_new_window(mlx_connection, 1200, 1200, "fdf");


	// bresenham_algorithm(100, 100, 800, 500, mlx_connection, mlx_window);
	// // bresenham_algorithm(800, 500, 100, 100, mlx_connection, mlx_window);
	// bresenham_algorithm(500, 500, 0, 0, mlx_connection, mlx_window);
	// bresenham_algorithm(500, 500, 1000, 0, mlx_connection, mlx_window);

	// bresenham_algorithm(500, 500, 0, 0, mlx_connection, mlx_window);
	// bresenham_algorithm(500, 500, 500, 0, mlx_connection, mlx_window);
	bresenham_algorithm(500, 500, 1000, 0, mlx_connection, mlx_window);
	// bresenham_algorithm(500, 500, 1000, 500, mlx_connection, mlx_window);
	// bresenham_algorithm(500, 500, 1000, 1000, mlx_connection, mlx_window);

	mlx_loop(mlx_connection);
}