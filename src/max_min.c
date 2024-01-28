/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:33:08 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/27 17:12:47 by pabeckha         ###   ########.fr       */
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

float	max_node_coordinate(Node *head, CoordinateExtractor extractor)
{
	Node	*current;
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

float	min_node_coordinate(Node *head, CoordinateExtractor extractor)
{
	Node	*current;
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
