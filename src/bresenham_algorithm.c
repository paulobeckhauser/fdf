/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/25 20:25:20 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_coordinates
{
    int x;
    int y;
} t_coordinates;


typedef struct Node{
    t_coordinates coord;
    struct Node *next;
    
} Node;


typedef struct algo_data{
    
    t_coordinates values;
    struct algo_data *next;
    int p_value;
    int dx;
    int dy;
    
} algo_data;


void bresenham_algorithm(int x1, int y1, int x2, int y2)
{
    algo_data *data;

    data = (algo_data*)malloc(sizeof(algo_data));

    data->values.x = x1;
    data->values.y = y1;

    data->dx = x2 - x1;
    data->dy = y2 - y1;
    data->p_value = (2 * data->dy) - data->dx;

    while (data->values.x <= x2)
    {
        printf("x: %d, y: %d, P: %d\n", data->values.x, data->values.y, data->p_value);
        printf("put_pixel(%d, %d)\n\n", data->values.x, data->values.y);
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
    Node *head = NULL;
    Node *prev = NULL;
    Node* newNode;


    newNode = (Node*)malloc(sizeof(Node));
    
    newNode->coord.x = 1;
    newNode->coord.y = 1;
    newNode->next = NULL;

    if (prev == NULL)
        head = newNode;
    else
        prev->next = newNode;
    prev = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    
    newNode->coord.x = 8;
    newNode->coord.y = 5;
    newNode->next = NULL;

    if (prev == NULL)
        head = newNode;
    else
        prev->next = newNode;
    prev = newNode;


    bresenham_algorithm(1, 1, 8, 5);





    // // Bresenham's Algorithm

    // algo_data *data;

    // data = (algo_data*)malloc(sizeof(algo_data));


    // Node *current;
    // current = head;
    
    // data->values.x = current->coord.x;
    // data->values.y = current->coord.y;
    // // printf("x: %d , %d\n", data->values.x, data->values.y);

    // data->dx = current->next->coord.x - current->coord.x;
    // data->dy = current->next->coord.y - current->coord.y;
    // printf("x: %d\n", data->values.x);
    // printf("y: %d\n", data->values.y);

    // data->p_value = (2 * data->dy) - data->dx;
    // printf("P: %d\n", data->p_value);
    // printf("\n\n");

    // while (current->coord.x <= current->next->coord.x)
    // {
    //     printf("x: %d, y: %d, P: %d\n", current->coord.x, current->coord.y, data->p_value);
    //     printf("put_pixel(%d, %d)\n\n", current->coord.x, current->coord.y);
    //     current->coord.x++;
    //     if (data->p_value < 0)
    //         data->p_value = data->p_value + (2 * data->dy);
    //     else
    //     {
    //         data->p_value = data->p_value + (2 * data->dy) - (2 * data->dx);
    //         current->coord.y++;
    //     }
    // }
    
    

    
}
    
    
    
