/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:27:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 23:21:21 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

t_map *new_list(char *line, int y)
{
    int x;
    char **split_result;
    t_map *s_list;

    x = 0;
    s_list = NULL;
    split_result = ft_split(line, ' ');
    if (!split_result)
    {
        clean_split(split_result);
        return (NULL);
    }
    while (split_result[x])
    {
        s_list = insert_node(s_list, new_node(x, y, ft_atoi(split_result[x])));
        x++;
    }
    s_list->width = x;
    clean_split(split_result);
    return (s_list);
}
