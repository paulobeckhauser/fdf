/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 20:25:51 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	correct_negative(t_node *head)
{
	t_node	*current;
	float	minX;
	float	minY;
	float	shiftX;
	float	shiftY;

	minX = MAX_FLOAT;
    minY = MAX_FLOAT;
	current = head;
	while (current != NULL)
	{
		minX = fmin(minX, fmin(current->iso_coord.x, fmin(current->right.x,
						current->down.x)));
		minY = fmin(minY, fmin(current->iso_coord.y, fmin(current->right.y,
						current->down.y)));
		current = current->next;
	}
	if (minX < 0)
		shiftX = -minX;
	else
		shiftX = 0;
	if (minY < 0)
		shiftY = -minY;
	else
		shiftY = 0;
	current = head;
	while (current != NULL)
	{
		current->iso_coord.x += shiftX;
		current->right.x += shiftX;
		current->down.x += shiftX;
		current->iso_coord.y += shiftY;
		current->right.y += shiftY;
		current->down.y += shiftY;
		current = current->next;
	}
}

void	scale(t_node *head, float scale_factor)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		current->iso_coord.x *= scale_factor;
		current->right.x *= scale_factor;
		current->down.x *= scale_factor;
		current->iso_coord.y *= scale_factor;
		current->right.y *= scale_factor;
		current->down.y *= scale_factor;
		current = current->next;
	}
}

void	centering(t_node *head)
{
	t_node	*current;
	float	maxX;
	float	maxY;
	float	minX;
	float	minY;
	float	centerShiftX;
	float	centerShiftY;

	maxX = MIN_FLOAT;
	maxY = MIN_FLOAT;
	current = head;
	while (current != NULL)
	{
		maxX = fmax(maxX, fmax(current->iso_coord.x, fmax(current->right.x,
						current->down.x)));
		maxY = fmax(maxY, fmax(current->iso_coord.y, fmax(current->right.y,
						current->down.y)));
		minX = fmin(minX, fmin(current->iso_coord.x, fmin(current->right.x,
						current->down.x)));
		minY = fmin(minY, fmin(current->iso_coord.y, fmin(current->right.y,
						current->down.y)));
		current = current->next;
	}
	centerShiftX = (WINDOW_WITDH - (maxX - minX)) / 2.0;
	centerShiftY = (WINDOW_HEIGHT - (maxY - minY)) / 2.0;
	current = head;
	while (current != NULL)
	{
		current->iso_coord.x += centerShiftX;
		current->right.x += centerShiftX;
		current->down.x += centerShiftX;
		current->iso_coord.y += centerShiftY;
		current->right.y += centerShiftY;
		current->down.y += centerShiftY;
		current = current->next;
	}
}
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
		{
			// bresenham_algorithm((current->iso_coord.x), (current->iso_coord.y),
			// 	(current->down.x), (current->down.y), &img);
			bresenham_algorithm(current->iso_coord, (current->down.x), (current->down.y), &img);
		}
		if (!isnan(current->right.x))
		{
			bresenham_algorithm(current->iso_coord, (current->right.x), (current->right.y), &img);
		}
		current = current->next;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, close_program, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
}

float	calculateMaxScaleFactor(t_node *head, float windowWidth,
		float windowHeight)
{
	float	minX;
	float	maxX;
    float	minY;
	float	maxY;
	t_node	*current;
	float	scaleX;
	float	scaleY;
	float	maxScaleFactor;

	maxX = MIN_FLOAT;
	maxY = MIN_FLOAT;
	minX = MAX_FLOAT, 
    minY = MAX_FLOAT;
	current = head;
	while (current != NULL)
	{
		minX = fmin(minX, fmin(current->iso_coord.x, fmin(current->right.x,
						current->down.x)));
		minY = fmin(minY, fmin(current->iso_coord.y, fmin(current->right.y,
						current->down.y)));
		maxX = fmax(maxX, fmax(current->iso_coord.x, fmax(current->right.x,
						current->down.x)));
		maxY = fmax(maxY, fmax(current->iso_coord.y, fmax(current->right.y,
						current->down.y)));
		current = current->next;
	}
	scaleX = (windowWidth - MARGIN) / (maxX - minX);
	scaleY = (windowHeight - MARGIN) / (maxY - minY);
	maxScaleFactor = fmin(scaleX, scaleY);
	return (maxScaleFactor);
}

void	draw(t_node *head)
{
	float	scale_factor;

	correct_negative(head);
	scale_factor = calculateMaxScaleFactor(head, WINDOW_WITDH, WINDOW_HEIGHT);
	scale(head, scale_factor);
	centering(head);
	draw_map(head);
}
