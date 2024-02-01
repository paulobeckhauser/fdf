/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:47:29 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/02 00:31:20 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	apply_centerization(t_node *head, float center_shift_x,
		float center_shift_y)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		current->iso_coord.x += center_shift_x;
		current->right.x += center_shift_x;
		current->down.x += center_shift_x;
		current->iso_coord.y += center_shift_y;
		current->right.y += center_shift_y;
		current->down.y += center_shift_y;
		current = current->next;
	}
}

void	calculate_shift(t_node *head, t_min_max min_max)
{
	float	center_shift_x;
	float	center_shift_y;

	center_shift_x = (WINDOW_WITDH - (min_max.max_x - min_max.min_x)) / 2.0;
	center_shift_y = (WINDOW_HEIGHT - (min_max.max_y - min_max.min_y)) / 2.0;
	apply_centerization(head, center_shift_x, center_shift_y);
}

void	centering(t_node *head)
{
	t_min_max	min_max;

	min_max = calculate_min_max(head);
	calculate_shift(head, min_max);
}
