/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/30 20:56:42 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"


# include <stdio.h>

void draw(Node *head)
{
    int mapWidth, mapHeight;
    
    float	max_x;
	float	max_y;

	max_x = max_node_coordinate(head, extract_x);
	max_y = max_node_coordinate(head, extract_y);


    mapWidth = WINDOW_WITDH;
    mapHeight = WINDOW_HEIGHT;

    int centerX = mapWidth / 2;
    int centerY = mapHeight / 2;

    printf("max_x: %f\n", max_x);
    printf("max_y: %f\n", max_y);

    printf("centerX: %d\n", centerX);
    printf("centerY: %d\n", centerY);
    
    // centerX = 0;
    // centerY = 0;
    
    
    
    
    t_data img;
    void *mlx_connection;
    void *mlx_window;
	Node *current;
	float factor_mult = 1.0;
    // // float factor_sum = 600.0;
    // float factor_sum = 0.0;

	mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, WINDOW_WITDH, WINDOW_HEIGHT, "fdf");
    img.img = mlx_new_image(mlx_connection, WINDOW_HEIGHT, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    current = head;
	// while(current != NULL)
    // {
    //     if (!isnan(current->down.x))
    //     {
    //         bresenham_algorithm((current->iso_coord.x * factor_mult + factor_sum - centerX), 
    //                             (current->iso_coord.y * factor_mult + factor_sum + centerY), 
    //                             (current->down.x * factor_mult + factor_sum - centerX), 
    //                             (current->down.y * factor_mult + factor_sum + centerY), 
    //                             &img);
    //     }
    //     if (!isnan(current->right.x))
    //     {
    //         bresenham_algorithm((current->iso_coord.x * factor_mult + factor_sum - centerX), 
    //                             (current->iso_coord.y * factor_mult + factor_sum + centerY), 
    //                             (current->right.x * factor_mult + factor_sum - centerX), 
    //                             (current->right.y * factor_mult + factor_sum + centerY),
    //             &img);
    //     }

    //     current = current->next;		
    // }
    while(current != NULL)
    {
        if (!isnan(current->down.x))
        {
            bresenham_algorithm((current->iso_coord.x + centerX) * factor_mult, 
                                (current->iso_coord.y + centerY) * factor_mult, 
                                (current->down.x + centerX) * factor_mult, 
                                (current->down.y+ centerY) * factor_mult, 
                                &img);
        }
        if (!isnan(current->right.x))
        {
            bresenham_algorithm((current->iso_coord.x + centerX) * factor_mult, 
                                (current->iso_coord.y + centerY) * factor_mult, 
                                (current->right.x + centerX) * factor_mult, 
                                (current->right.y + centerY) * factor_mult,
                &img);
        }

        current = current->next;		
    }
	mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);
    mlx_loop(mlx_connection);
}
