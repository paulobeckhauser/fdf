/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:38:23 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 23:40:21 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_node	*read_map(t_node *head, char *map_name)
{
	int		fd;
	char	*line;
	char	**array;
	int		x_value;
	int		y_value;
	t_node	*prev;
	t_node	*new_node;

	fd = open(map_name, O_RDONLY);
	y_value = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		array = ft_split(line, ' ');
		x_value = 0;
		while (array[x_value])
		{
			new_node = (t_node *)malloc(sizeof(t_node));
			new_node->coord.x = x_value;
			new_node->coord.y = y_value;
			new_node->coord.z = ft_atoi(array[x_value]);
			new_node->next = NULL;
			new_node->prev = prev;
			if (prev == NULL)
				head = new_node;
			else
				prev->next = new_node;
			prev = new_node;
			x_value++;
		}
		free(array);
		y_value++;
	}
	return (head);
}
