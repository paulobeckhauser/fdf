/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/26 00:44:05 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

#include <stdio.h>


// DELETE LATER
// static void print_coords(Node *head)
// {
//     Node *current;
    
//     current = head;

//     while (current != NULL)
//     {
//         printf("x: %f, y: %f\n", current->coord.x, current->coord.y);
//         current = current->next;
//     }
// }


void bresenham_algorithm(int x1, int y1, int x2, int y2, void *mlx_connection, void *mlx_window)
{
    bresenham_data *data;

    data = (bresenham_data*)malloc(sizeof(bresenham_data));

    data->values.x = x1;
    data->values.y = y1;

    data->dx = x2 - x1;
    data->dy = y2 - y1;
    data->p_value = (2 * data->dy) - data->dx;

    while (data->values.x <= x2)
    {
        // printf("x: %f, y: %f, P: %d\n", data->values.x, data->values.y, data->p_value);
        // printf("put_pixel(%f, %f)\n\n", data->values.x, data->values.y);
        mlx_pixel_put(mlx_connection, mlx_window, data->values.x, data->values.y, 0xff0000);
        data->values.x++;
        if (data->p_value < 0)
            data->p_value = data->p_value + (2 * data->dy);
        else
        {
            data->p_value = data->p_value + (2 * data->dy) - (2 * data->dx);
            data->values.y++;
        }
    }
}


int main(void)
{
    int fd;    
    char *line;
    char **array;
    
    int x_value;
    int y_value;

    // here both head and prev are temporary pointers
    // Both are not part of the structure yet.
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
            // Create a new Node
            Node* newNode;
            
            newNode = (Node*)malloc(sizeof(Node));
            newNode->coord.x = x_value;
            newNode->coord.y = y_value;
            newNode->coord.z = ft_atoi(array[x_value]);
            newNode->next = NULL;
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


    



    

    // print_coords(head);

    // ft_printf("\n\n\n\n");

	// Node *current;


    // Z-AXIS ROTATE BY 45 degrees 
	// current = head;
	// while (current != NULL)
	// {
	// 	current->coord.x = (COS_45 * current->coord.x) - (SIN_45 * current->coord.y);
    //     current->coord.y = (SIN_45 * current->coord.x) + (COS_45 * current->coord.y);
    //     current = current->next;
	// }
    // print_coords(head);


    // X-AXIS ROTATE BY ARCTAN ROOT OF 2
    // current = head;
	// while (current != NULL)
	// {
    //     current->coord.y = (COS_ARCTAN_ROOT2 * current->coord.y) - (SIN_ARCTAN_ROOT2 * current->coord.z);
    //     current = current->next;
	// }

    
    // print_coords(head);


    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 1200, 900, "fdf");
    

    // mlx_pixel_put(mlx_connection, mlx_window, 100, 100, 0xff0000);
    // mlx_pixel_put(mlx_connection, mlx_window, 200, 200, 0xff0000);
    // mlx_pixel_put(mlx_connection, mlx_window, 300, 300, 0xff0000);


    // current = head;

    // while (current != NULL)
    // {
    //     // mlx_pixel_put(mlx_connection, mlx_window, current->coord.x, current->coord.y, 0xff0000);
    //     printf("x: %f, y: %f\n", current->coord.x, current->coord.y);
    //     current = current->next;
    // }


    // Node *outer_current = head;
    
    // while (outer_current != NULL)
    // {
    //     Node *inner_current = outer_current->next;
    //     while (inner_current != NULL)
    //     {
    //         printf("x1: %f, y1: %f, x2: %f, y2: %f\n", outer_current->coord.x, outer_current->coord.y, inner_current->coord.x, inner_current->coord.y);
    //         inner_current = inner_current->next;
    //     }
    //     printf("\n");
    //     outer_current = outer_current->next;
    // }

    Node *outer_current = head;
    
    while (outer_current != NULL)
    {
        Node *inner_current = outer_current->next;
        while (inner_current != NULL)
        {
            // printf("x1: %f, y1: %f, x2: %f, y2: %f\n", outer_current->coord.x, outer_current->coord.y, inner_current->coord.x, inner_current->coord.y);
            bresenham_algorithm(outer_current->coord.x * 500, outer_current->coord.y * 500, inner_current->coord.x * 500, inner_current->coord.y * 500, mlx_connection, mlx_window);
            inner_current = inner_current->next;
        }
        outer_current = outer_current->next;
    }



    // bresenham_algorithm(1, 1, 8, 5);

    // bresenham_algorithm(0 * 500, 0 * 500, 1 * 500, 0 * 500, mlx_connection, mlx_window);





    // current = head;

    // while (current != NULL)
    // {
    //     bresenham_algorithm(, mlx_connection, mlx_window);
    //     // printf("x: %f, y: %f\n", current->coord.x, current->coord.y);
    //     current = current->next;
    // }




    // bresenham_algorithm(0 * 500, 0 * 500, 1 * 500, 0 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(0 * 500, 0 * 500, 2 * 500, 0 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(0 * 500, 0 * 500, 0 * 500, 1 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(0 * 500, 0 * 500, 1 * 500, 0 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(0 * 500, 0 * 500, 1 * 500, 0 * 500, mlx_connection, mlx_window);





    
    // bresenham_algorithm(1 * 500, 0 * 500, 2 * 500, 0 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(2 * 500, 0 * 500, 0 * 500, 1 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(0 * 500, 1 * 500, 1 * 500, 1 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(1 * 500, 1 * 500, 2 * 500, 1 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(2 * 500, 1 * 500, 0 * 500, 2 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(0 * 500, 2 * 500, 1 * 500, 2 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(1 * 500, 2 * 500, 2 * 500, 2 * 500, mlx_connection, mlx_window);
    // bresenham_algorithm(2 * 500, 2 * 500, 0 * 500, 0 * 500, mlx_connection, mlx_window);



    // // bresenham_algorithm(700, 600, 800, 800, mlx_connection, mlx_window);
    // // bresenham_algorithm(700, 600, 800, 800, mlx_connection, mlx_window);
    // // bresenham_algorithm(700, 600, 800, 800, mlx_connection, mlx_window);
    // // bresenham_algorithm(700, 600, 800, 800, mlx_connection, mlx_window);


//     x: 0.000000, y: 0.000000
// x: 1.000000, y: 0.000000
// x: 2.000000, y: 0.000000
// x: 0.000000, y: 1.000000
// x: 1.000000, y: 1.000000
// x: 2.000000, y: 1.000000
// x: 0.000000, y: 2.000000
// x: 1.000000, y: 2.000000
// x: 2.000000, y: 2.000000

    mlx_loop(mlx_connection);
    

    

    



    // Bresenham's Algorithm

    

    



    

    
        

    return (0);
}
