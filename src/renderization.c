/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:32:59 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 23:35:42 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"





void    render(t_map *s_map, mlx_image_t *img)
{
    float **map_matrix;
    float **converted_matrix;

    draw_background(img);
    map_matrix = get_map_matrix(s_map);
    converted_matrix = convert_matrix(s_map, map_matrix);
    draw_map(s_map, img, converted_matrix);
    return ;
}

