/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:31:27 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 22:34:40 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

t_map *new_node(int x, int y, int z)
{
    t_map *node;

    node = malloc(sizeof(t_map));
    if (!node)
        return (NULL);
    node->s_coordinate = malloc(sizeof(t_coordinates));
    if (!node->s_coordinate)
    {
        free(node);
        return (NULL);
    }
    node->s_coordinate->x = x;
    node->s_coordinate->y = y;
    node->s_coordinate->z = z;
    node->next = NULL;
    return (node);
}
