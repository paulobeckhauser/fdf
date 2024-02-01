/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_negative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:46:01 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/02 00:37:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	apply_correction(t_node *head, float shift_x, float shift_y)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		current->iso_coord.x += shift_x;
		current->right.x += shift_x;
		current->down.x += shift_x;
		current->iso_coord.y += shift_y;
		current->right.y += shift_y;
		current->down.y += shift_y;
		current = current->next;
	}
}

void	find_min_values(t_node *head, float *min_x, float *min_y)
{
	t_node	*current;

	current = head;
	*min_x = MAX_FLOAT;
	*min_y = MAX_FLOAT;
	while (current != NULL)
	{
		*min_x = fmin(*min_x, fmin(current->iso_coord.x, fmin(current->right.x,
						current->down.x)));
		*min_y = fmin(*min_y, fmin(current->iso_coord.y, fmin(current->right.y,
						current->down.y)));
		current = current->next;
	}
}

void	correct_negative(t_node *head)
{
	float	min_x;
	float	min_y;
	float	shift_x;
	float	shift_y;

	find_min_values(head, &min_x, &min_y);
	if (min_x < 0)
		shift_x = -min_x;
	else
		shift_x = 0;
	if (min_y < 0)
		shift_y = -min_y;
	else
		shift_y = 0;
	apply_correction(head, shift_x, shift_y);
}
