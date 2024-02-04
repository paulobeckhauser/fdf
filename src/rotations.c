/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:05:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/04 16:37:39 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate_z_45_degrees(struct Node *current)
{
	double	old_x;
	double	old_y;
	double	old_z;

	old_x = current->iso_coord.x;
	old_y = current->iso_coord.y;
	old_z = current->iso_coord.z;
	current->iso_coord.x = ((cos(45 * (M_PI / 180.0))) * old_x) - ((sin(45
					* (M_PI / 180.0))) * old_y);
	current->iso_coord.y = ((sin(45 * (M_PI / 180.0))) * old_x) + ((cos(45
					* (M_PI / 180.0))) * old_y);
	current->iso_coord.z = old_z;
}

void	rotate_x_55_degrees(struct Node *current)
{
	double	old_x;
	double	old_y;
	double	old_z;

	old_x = current->iso_coord.x;
	old_y = current->iso_coord.y;
	old_z = current->iso_coord.z;
	current->iso_coord.x = current->iso_coord.x;
	current->iso_coord.y = ((cos(54.74 * (M_PI / 180.0))) * old_y) - ((sin(54.74
					* (M_PI / 180.0))) * old_z);
	current->iso_coord.z = ((sin(54.74 * (M_PI / 180.0))) * old_y) + ((cos(54.74
					* (M_PI / 180.0))) * old_z);
}

void	isometric_projection(t_node *head)
{
	t_node	*current;
	double	old_x;
	double	old_y;
	double	old_z;

	current = head;
	while (current != NULL)
	{
		current->iso_coord = current->coord;
		rotate_z_45_degrees(current);
		rotate_x_55_degrees(current);
		current = current->next;
	}
}
