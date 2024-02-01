/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:38:23 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 13:41:53 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

Node	*read_map(Node *head, char *map_name)
{
	int		fd;
	char	*line;
	char	**array;
	int		x_value;
	int		y_value;
	Node	*prev;
	Node 	*newNode;

	prev = NULL;
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
			newNode = (Node *)malloc(sizeof(Node));
			newNode->coord.x = x_value;
			newNode->coord.y = y_value;
			newNode->coord.z = ft_atoi(array[x_value]);
			newNode->next = NULL;
			newNode->prev = prev;
			if (prev == NULL)
				head = newNode;
			else
				prev->next = newNode;
			prev = newNode;
			x_value++;
		}
		free(array);
		y_value++;
	}
	return (head);
}
