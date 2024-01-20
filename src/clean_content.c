/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:36:30 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 22:42:41 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void clean_structure(t_map *s_map)
{
    t_map *temp;

    while (s_map != NULL)
    {
        temp = s_map;
        s_map = s_map->next;
        if (temp->s_coordinate != NULL)
        {
            free(temp->s_coordinate);
            temp->s_coordinate = NULL;
        }
        free(temp);
    }
}

void clean_split(char **split_result)
{
    int i;

    i = 0;
    while (split_result[i])
    {
        free(split_result[i]);
        i++;
    }
    free(split_result);
}

void clean_matrix(float **map_matrix)
{
    int i;

    i = 0;
    while (map_matrix[i])
    {
        free(map_matrix[i] != NULL);
        i++;
    }
    free(map_matrix);
}
