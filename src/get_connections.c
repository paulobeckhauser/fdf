/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:54:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 23:03:29 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_coordinates_to_nan(t_coordinates *iso_coord)
{
	iso_coord->x = NAN;
	iso_coord->y = NAN;
	iso_coord->z = NAN;
}

void	set_down_values(t_node *head)
{
	t_node	*down_node;

	down_node = head->next;
	while (down_node != NULL)
	{
		if (down_node->coord.x == head->coord.x
			&& down_node->coord.y == head->coord.y + 1)
		{
			head->down = down_node->iso_coord;
			break ;
		}
		down_node = down_node->next;
	}
}

void	get_connections(t_node *head)
{
	while (head != NULL)
	{
		if (head->coord.x != max_node_coordinate(head, extract_x))
			head->right = head->next->iso_coord;
		else
			set_coordinates_to_nan(&head->right);
		if (head->coord.y != max_node_coordinate(head, extract_y))
			set_down_values(head);
		else
			set_coordinates_to_nan(&head->down);
		head = head->next;
	}
}
