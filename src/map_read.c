/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:23:15 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 22:20:47 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_map	*map_read(const char *argv)
{
	t_map	*s_temp;
	char	*line;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	s_temp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!(line))
			break ;
		s_temp = insert_node(s_temp, new_list(line, i));
		i++;
		free(line);
	}
	if (s_temp == NULL || s_temp->width < 2)
	{
		clean_data(s_temp);
		return (NULL);
	}
	s_temp->height = i;
	close(fd);
	return (s_temp);
}
