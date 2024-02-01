/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:54:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 22:51:22 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_coordinates_to_nan(t_coordinates *iso_coord)
{
	iso_coord->x = NAN;
	iso_coord->y = NAN;
	iso_coord->z = NAN;
}

void	get_connections(t_node *head)
{
	t_node	*current;
	t_node	*down_node;
	t_node	*up_node;
	float	max_x;
	float	max_y;

	max_x = max_node_coordinate(head, extract_x);
	max_y = max_node_coordinate(head, extract_y);

	current = head;
	while (current != NULL)
	{
		if (current->coord.x != 0)
			current->left = current->prev->iso_coord;
		else
			set_coordinates_to_nan(&current->left);
		if (current->coord.x != max_x)
			current->right = current->next->iso_coord;
		else
			set_coordinates_to_nan(&current->right);
		if (current->coord.y != 0)
		{
			up_node = current->prev;
			while (up_node != NULL)
			{
				if (up_node->coord.x == current->coord.x
					&& up_node->coord.y == current->coord.y - 1)
				{
					current->up = up_node->iso_coord;
					break ;
				}
				up_node = up_node->prev;
			}
		}
		else
			set_coordinates_to_nan(&current->up);
		if (current->coord.y != max_y)
		{
			down_node = current->next;
			while (down_node != NULL)
			{
				if (down_node->coord.x == current->coord.x
					&& down_node->coord.y == current->coord.y + 1)
				{
					current->down = down_node->iso_coord;
					break ;
				}
				down_node = down_node->next;
			}
		}
		else
			set_coordinates_to_nan(&current->down);
		current = current->next;
	}
}
