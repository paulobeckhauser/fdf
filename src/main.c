/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/22 22:10:22 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"




typedef struct {
   int x;
   int y;
   char *z;
} Coordinates;




typedef struct Node{
    
    Coordinates coord;
    struct Node *next;
} Node;




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

    
    

    

    
    fd = open("maps/paulo_test.fdf", O_RDONLY);

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
            newNode->coord.z = array[x_value];

            // Link the new Node to the previous Node
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


    
    

    

    
    



// PRINT THE DOTS --DELETE LATER

    Node *current;
    
    current = head;

    while (current != NULL)
    {
        ft_printf("x: %d, y: %d, z: %s\n", current->coord.x, current->coord.y, current->coord.z);
        current = current->next;
    }


    
    
    



    
    

    


    
    
    return (0);
}
