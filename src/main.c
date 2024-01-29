/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/29 22:46:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

#include <stdio.h>



int main(void)
{
    int fd;    
    char *line;
    char **array;
    
    int x_value;
    int y_value;

    Node *head = NULL;
    Node *prev = NULL;

    // fd = open("maps/plat.fdf", O_RDONLY);
    // fd = open("maps/42.fdf", O_RDONLY);
    fd = open("maps/new_test.fdf", O_RDONLY);

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
            Node* newNode;
            
            newNode = (Node*)malloc(sizeof(Node));
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
        free (array);
        y_value++;
    }

    // Node *current;
    
    // current = head;

    // while (current != NULL)
    // {
    //     printf("x: %f, y: %f, z: %f\n", current->coord.x, current->coord.y, current->coord.z);
    //     current = current->next;
    // }


    // make a exact copy of coord to iso coord

    Node *current;
    
    current = head;

    while (current != NULL)
    {
        current->iso_coord = current->coord;
        current = current->next;
    }

    // // Node *current;

	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
    
    min_x = min_node_coordinate(head, extract_x);
	min_y = min_node_coordinate(head, extract_y);
	max_x = max_node_coordinate(head, extract_x);
	max_y = max_node_coordinate(head, extract_y);

    double oldX, oldY, oldZ;
    current = head;
	while (current != NULL)
	{
		
        oldX = current->iso_coord.x;
        oldY = current->iso_coord.y;
        oldZ = current->iso_coord.z;
        
        current->iso_coord.x = (COS_45 * oldX) - (SIN_45 * oldY);
        current->iso_coord.y = (SIN_45 * oldX) + (COS_45 * oldY);

        /// ATTENTION
        current->iso_coord.z = oldZ * 2; 

        
        current = current->next;
	}

    current = head;
	while (current != NULL)
	{
		
        oldX = current->iso_coord.x;
        oldY = current->iso_coord.y;
        oldZ = current->iso_coord.z;
        
        current->iso_coord.x = current->iso_coord.x;
        current->iso_coord.y = (COS_35 * oldY) - (SIN_35 * oldZ);
        current->iso_coord.z = (SIN_35 * oldY) + (COS_35 * oldZ);
        current = current->next;
	}


    

    // current = head;


    // printf("%f\n", COS_45);
    // printf("%f\n", SIN_45);
    
    // while (current != NULL)
    // {
    //     printf("x: %f, y: %f, z: %f\n", current->coord.x, current->coord.y, current->coord.z);
    //     printf("x: %f, y: %f, z: %f\n\n", current->iso_coord.x, current->iso_coord.y, current->iso_coord.z);
    //     current = current->next;
    // }

    get_connections(head, max_x, max_y);


    // current = head;
    // while(current != NULL)
    // {
    //     printf("\nDOT: (%f, %f, %f)\n", current->coord.x, current->coord.y, current->coord.z);
    //     printf("ISO_DOT: (%f, %f, %f)\n\n", current->iso_coord.x, current->iso_coord.y, current->iso_coord.z);
    //     // if (!isnan(current->left.x))
    //     //     printf("Left: (%f, %f, %f)\n", current->left.x, current->left.y, current->left.z);
    //     // if (!isnan(current->right.x))
    //     //     printf("Right: (%f, %f, %f)\n", current->right.x, current->right.y, current->right.z);
    //     // if (!isnan(current->up.x))
    //     //     printf("Up: (%f, %f, %f)\n", current->up.x, current->up.y, current->up.z);
    //     // if (!isnan(current->down.x))
    //     //     printf("Down: (%f, %f, %f)\n", current->down.x, current->down.y, current->down.z);
    //     // printf("\n\n");
    //     current = current->next;
    // }
    // print_coords(head);


    float factor_mult = 200.0;
    float factor_sum = 500.0;



    t_data img;
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init();

    mlx_window = mlx_new_window(mlx_connection, WINDOW_WITDH, WINDOW_HEIGHT, "fdf");

    
    img.img = mlx_new_image(mlx_connection, WINDOW_HEIGHT, WINDOW_HEIGHT);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    current = head;
    while(current != NULL)
    {
        if (!isnan(current->down.x))
        {
            bresenham_algorithm((current->iso_coord.x * factor_mult + factor_sum), 
                                (current->iso_coord.y * factor_mult + factor_sum), 
                                (current->down.x * factor_mult + factor_sum), 
                                (current->down.y * factor_mult + factor_sum), 
                                &img);
        }
        if (!isnan(current->right.x))
        {
            bresenham_algorithm((current->iso_coord.x * factor_mult + factor_sum), (current->iso_coord.y * factor_mult + factor_sum), 
                (current->right.x * factor_mult + factor_sum), (current->right.y * factor_mult + factor_sum),
                &img);
        }

        current = current->next;
    }
    

    mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);
    mlx_loop(mlx_connection);
    return (0);
}
