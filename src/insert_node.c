/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:19:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 22:20:07 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

t_map *insert_node(t_map *head, t_map *s_list)
{
    t_map *current;

    current = head;
    if (!s_list)
        return (NULL);
    if (head == NULL)
    {
        head = s_list;
        return (head);
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = s_list;
        current = current->next;
    }
    return (head);
}