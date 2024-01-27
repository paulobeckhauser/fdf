/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/27 12:41:27 by pabeckha         ###   ########.fr       */
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
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    
    current = head;
    
    min_x = min_node_coordinate(head, extract_x);
    min_y = min_node_coordinate(head, extract_y);
    max_x = max_node_coordinate(head, extract_x);
    max_y = max_node_coordinate(head, extract_y);

    printf("\n");

    while (current != NULL)
    {
         //First column
        if (current->coord.x == min_x)
        {
           if (current->coord.y == min_y)     
                printf("Right and Down\n");
            else if(current->coord.y == max_y)
                printf("Right and Up\n");
            else
                printf("Right, Up and Down\n");
        }
        
        // Last Column
        else if (current->coord.x == max_x)
        {
            if (current->coord.y == min_y)
                printf("Left and Down\n");
            else if(current->coord.y == max_y)
                printf("Left and Up\n");
            else
                printf("Left, Up and Down\n");
        }
        
        // Middle columns
        else
        {
            if (current->coord.y == min_y)
                printf("Left, Right and Down\n");
            else if(current->coord.y == max_y)
                printf("Left, Right and Up\n");
            else
                printf("Left, Right, Up and Down\n");
        }

        
        
        printf("x: %f, y: %f\n\n", current->coord.x, current->coord.y);
        current = current->next;
    }


    
    
    


    



 

    return (0);
}
