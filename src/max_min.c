/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:33:08 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/02 00:30:52 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	extract_x(t_coordinates coord)
{
	return (coord.x);
}

float	extract_y(t_coordinates coord)
{
	return (coord.y);
}

float	max_node_coordinate(t_node *head, t_coordinate_extractor extractor)
{
	t_node	*current;
	float	max_value;
	float	current_value;

	current = head;
	max_value = extractor(current->coord);
	while (current != NULL)
	{
		current_value = extractor(current->coord);
		if (current_value > max_value)
			max_value = current_value;
		current = current->next;
	}
	return (max_value);
}

float	min_node_coordinate(t_node *head, t_coordinate_extractor extractor)
{
	t_node	*current;
	float	min_value;
	float	current_value;

	current = head;
	min_value = extractor(current->coord);
	while (current != NULL)
	{
		current_value = extractor(current->coord);
		if (current_value < min_value)
			min_value = current_value;
		current = current->next;
	}
	return (min_value);
}

t_min_max	calculate_min_max(t_node *head)
{
	t_min_max	min_max;
	t_node		*current;

	current = head;
	min_max.max_x = MIN_FLOAT;
	min_max.max_y = MIN_FLOAT;
	min_max.min_x = MAX_FLOAT;
	min_max.min_y = MAX_FLOAT;
	while (current != NULL)
	{
		min_max.max_x = fmax(min_max.max_x, fmax(current->iso_coord.x,
					fmax(current->right.x, current->down.x)));
		min_max.max_y = fmax(min_max.max_y, fmax(current->iso_coord.y,
					fmax(current->right.y, current->down.y)));
		min_max.min_x = fmin(min_max.min_x, fmin(current->iso_coord.x,
					fmin(current->right.x, current->down.x)));
		min_max.min_y = fmin(min_max.min_y, fmin(current->iso_coord.y,
					fmin(current->right.y, current->down.y)));
		current = current->next;
	}
	return (min_max);
}
