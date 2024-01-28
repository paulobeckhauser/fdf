/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/27 18:48:50 by pabeckha         ###   ########.fr       */
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

    Node *current;
    
    // current = head;

    // while (current != NULL)
    // {
    //     printf("x: %f, y: %f, z: %f\n", current->coord.x, current->coord.y, current->coord.z);
    //     current = current->next;
    // }

    
    


    
    // Node *current;

	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
    
    min_x = min_node_coordinate(head, extract_x);
	min_y = min_node_coordinate(head, extract_y);
	max_x = max_node_coordinate(head, extract_x);
	max_y = max_node_coordinate(head, extract_y);

    get_connections(head, max_x, max_y);

    // current = head;

	// while (current != NULL)
	// {
	// 	current->coord.x = current->coord.x - current->coord.y;
    //     current->left.x = current->left.x - current->left.y;
    //     current->right.x = current->right.x - current->right.y;
    //     current->up.x = current->up.x - current->up.y;
    //     current->down.x = current->down.x - current->down.y;

        
    //     current->coord.y = (current->coord.x +  current->coord.y) / 2 - current->coord.z;
    //     current->left.y = (current->left.x +  current->left.y) / 2 - current->left.z;
    //     current->right.y = (current->right.x +  current->right.y) / 2 - current->right.z;
    //     current->up.y = (current->up.x +  current->up.y) / 2 - current->up.z;
    //     current->down.y = (current->down.x +  current->down.y) / 2 - current->down.z;

    //     current = current->next;
    // }

    // current = head;
	// while (current != NULL)
	// {
	// 	current->coord.x = (COS_45 * current->coord.x) - (SIN_45 * current->coord.y);
    //     current->left.x = (COS_45 * current->left.x) - (SIN_45 * current->left.y);
    //     current->right.x = (COS_45 * current->right.x) - (SIN_45 * current->right.y);
    //     current->up.x = (COS_45 * current->up.x) - (SIN_45 * current->up.y);
    //     current->down.x = (COS_45 * current->down.x) - (SIN_45 * current->down.y);

        
    //     current->coord.y = (SIN_45 * current->coord.x) + (COS_45 * current->coord.y);
    //     current->left.y = (SIN_45 * current->left.x) + (COS_45 * current->left.y);
    //     current->right.y = (SIN_45 * current->right.x) + (COS_45 * current->right.y);
    //     current->up.y = (SIN_45 * current->up.x) + (COS_45 * current->up.y);
    //     current->down.y = (SIN_45 * current->down.x) + (COS_45 * current->down.y);

        
    //     current = current->next;
	// }


    // ROTATE X ROOT ARCTAN
    // current = head;
	// while (current != NULL)
	// {
    //     current->coord.y = (COS_ARCTAN_ROOT2 * current->coord.y) - (SIN_ARCTAN_ROOT2 * current->coord.z);
    //     current->left.y = (COS_ARCTAN_ROOT2 * current->left.y) - (SIN_ARCTAN_ROOT2 * current->left.z);
    //     current->right.y = (COS_ARCTAN_ROOT2 * current->right.y) - (SIN_ARCTAN_ROOT2 * current->right.z);
    //     current->up.y = (COS_ARCTAN_ROOT2 * current->up.y) - (SIN_ARCTAN_ROOT2 * current->up.z);
    //     current->down.y = (COS_ARCTAN_ROOT2 * current->down.y) - (SIN_ARCTAN_ROOT2 * current->down.z);
        
    
    //     current = current->next;
	// }



    



    // current = head;
    // while(current != NULL)
    // {
    //     printf("\nDOT: (%f, %f, %f)\n\n", current->coord.x, current->coord.y, current->coord.z);
    //     if (!isnan(current->left.x))
    //         printf("Left: (%f, %f, %f)\n", current->left.x, current->left.y, current->left.z);
    //     if (!isnan(current->right.x))
    //         printf("Right: (%f, %f, %f)\n", current->right.x, current->right.y, current->right.z);
    //     if (!isnan(current->up.x))
    //         printf("Up: (%f, %f, %f)\n", current->up.x, current->up.y, current->up.z);
    //     if (!isnan(current->down.x))
    //         printf("Down: (%f, %f, %f)\n", current->down.x, current->down.y, current->down.z);
    //     printf("\n\n");
    //     current = current->next;
    // }
    // print_coords(head);


    int factor_mult = 250;
    int factor_sum = 500;

    
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init();

    mlx_window = mlx_new_window(mlx_connection, 1200, 1200, "fdf");
    
    

    current = head;

    while(current != NULL)
    {
        if (!isnan(current->left.x))
            bresenham_algorithm((int)(current->coord.x * factor_mult + factor_sum), (int)(current->coord.y * factor_mult + factor_sum), (int)(current->left.x * factor_mult + factor_sum), (int)(current->left.y * factor_mult + factor_sum),
            mlx_connection, mlx_window);
        if (!isnan(current->right.x))
            bresenham_algorithm((int)(current->coord.x * factor_mult + factor_sum), (int)(current->coord.y * factor_mult + factor_sum), (int)(current->right.x * factor_mult + factor_sum), (int)(current->right.y * factor_mult + factor_sum),
            mlx_connection, mlx_window);
        if (!isnan(current->up.x))
            bresenham_algorithm((int)(current->coord.x * factor_mult + factor_sum), (int)(current->coord.y * factor_mult + factor_sum), (int)(current->up.x * factor_mult + factor_sum), (int)(current->up.y * factor_mult + factor_sum),
            mlx_connection, mlx_window);
        if (!isnan(current->down.x))
            bresenham_algorithm((int)(current->coord.x * factor_mult + factor_sum), (int)(current->coord.y * factor_mult + factor_sum), (int)(current->down.x * factor_mult + factor_sum), (int)(current->down.y * factor_mult + factor_sum),
            mlx_connection, mlx_window);
        current = current->next;
    }


    mlx_loop(mlx_connection);


    return (0);
}
