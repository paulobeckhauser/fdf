/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:05:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/30 14:15:18 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso_copy(Node *head)
{
	Node	*current;

	current = head;
	while (current != NULL)
	{
		current->iso_coord = current->coord;
		current = current->next;
	}
}

void	rotate_z_45(Node *head)
{
	Node	*current;
	double	old_x;
	double	old_y;
	double	old_z;

	current = head;
	while (current != NULL)
	{
		old_x = current->iso_coord.x;
		old_y = current->iso_coord.y;
		old_z = current->iso_coord.z;
		current->iso_coord.x = (COS_45 * old_x) - (SIN_45 * old_y);
		current->iso_coord.y = (SIN_45 * old_x) + (COS_45 * old_y);
		current->iso_coord.z = old_z;
		current = current->next;
	}
}

void	rotate_x_arctan_root2(Node *head)
{
	Node	*current;
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
		current->iso_coord.y = (COS_35 * old_y) - (SIN_35 * old_z);
		current->iso_coord.z = (SIN_35 * old_y) + (COS_35 * old_z);
		current = current->next;
	}
}
