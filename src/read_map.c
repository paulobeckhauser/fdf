/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:38:23 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/03 12:00:44 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

static t_node	*create_node(int x_value, int y_value, int z_value,
		t_node *prev)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->coord.x = x_value;
	new_node->coord.y = y_value;
	new_node->coord.z = z_value;
	new_node->next = NULL;
	new_node->prev = prev;
	return (new_node);
}

static void	process_array(t_node **head, t_node **prev, char **array, int y)
{
	t_node	*new_node;
	int		x;

	x = 0;
	while (array[x])
	{
		new_node = create_node(x, y, ft_atoi(array[x]), *prev);
		if (*prev == NULL)
			*head = new_node;
		else
			(*prev)->next = new_node;
		*prev = new_node;
		free(array[x]);
		x++;
	}
}

t_node	*read_map(t_node *head, char *map_name)
{
	int		fd;
	char	*line;
	char	**array;
	int		y;
	t_node	*prev;

	prev = NULL;
	fd = open(map_name, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		array = ft_split(line, ' ');
		free(line);
		if (array == NULL)
			return (NULL);
		process_array(&head, &prev, array, y);
		free(array);
		y++;
	}
	return (head);
}
