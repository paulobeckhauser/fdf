/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:43:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/02 00:44:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	max_scale_factor(t_node *head, float window_width, float window_height)
{
	float		scale_x;
	float		scale_y;
	float		max_scale_factor;
	t_min_max	min_max;

	min_max = calculate_min_max(head);
	scale_x = (window_width - MARGIN) / (min_max.max_x - min_max.min_x);
	scale_y = (window_height - MARGIN) / (min_max.max_y - min_max.min_y);
	max_scale_factor = fmin(scale_x, scale_y);
	return (max_scale_factor);
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
