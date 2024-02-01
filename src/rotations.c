/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:05:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 23:41:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso_copy(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		current->iso_coord = current->coord;
		current = current->next;
	}
}

void	rotate_z_45(t_node *head)
{
	t_node	*current;
	double	old_x;
	double	old_y;
	double	old_z;

	current = head;
	while (current != NULL)
	{
		old_x = current->iso_coord.x;
		old_y = current->iso_coord.y;
		old_z = current->iso_coord.z;
		current->iso_coord.x = ((cos(45 * (M_PI / 180.0))) * old_x) - ((sin(45
						* (M_PI / 180.0))) * old_y);
		current->iso_coord.y = ((sin(45 * (M_PI / 180.0))) * old_x) + ((cos(45
						* (M_PI / 180.0))) * old_y);
		current->iso_coord.z = old_z;
		current = current->next;
	}
}

void	rotate_x_arctan_root2(t_node *head)
{
	t_node	*current;
	double	old_x;
	double	old_y;
	double	old_z;

	current = head;
	while (current != NULL)
	{
		old_x = current->iso_coord.x;
		old_y = current->iso_coord.y;
		old_z = current->iso_coord.z;
		current->iso_coord.x = current->iso_coord.x;
		current->iso_coord.y = ((cos(54.74 * (M_PI / 180.0))) * old_y)
			- ((sin(54.74 * (M_PI / 180.0))) * old_z);
		current->iso_coord.z = ((sin(54.74 * (M_PI / 180.0))) * old_y)
			+ ((cos(54.74 * (M_PI / 180.0))) * old_z);
		current = current->next;
	}
}
