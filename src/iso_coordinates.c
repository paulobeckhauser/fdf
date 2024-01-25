/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:34:15 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/24 17:40:38 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"






void	iso_coordinates(Node *head)
{
	Node *current;

	current = head;
	while (current != NULL)
	{
		current->iso_coord.x_iso = current->coord.x ;


        
		current->iso_coord.y_iso = current->coord.x - current->coord.y;
		current = current->next;
	}
}
