/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 23:49:55 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

static int	close_program(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	return (0);
}

void	draw_map(t_node *head)
{
	t_data	img;
	t_vars	vars;
	t_node	*current;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_WITDH, WINDOW_HEIGHT, "fdf");
	img.img = mlx_new_image(vars.mlx, WINDOW_WITDH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	current = head;
	while (current != NULL)
	{
		if (!isnan(current->down.x))
			bresenham_algorithm(current->iso_coord, (current->down.x),
				(current->down.y), &img);
		if (!isnan(current->right.x))
			bresenham_algorithm(current->iso_coord, (current->right.x),
				(current->right.y), &img);
		current = current->next;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, close_program, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
}

void	draw(t_node *head)
{
	float	scale_factor;

	correct_negative(head);
	scale_factor = max_scale_factor(head, WINDOW_WITDH, WINDOW_HEIGHT);
	scale(head, scale_factor);
	centering(head);
	draw_map(head);
}
