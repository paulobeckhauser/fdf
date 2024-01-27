/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:10:31 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/27 12:20:26 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

// Made libraries
# include "../libs/libft/inc/libft.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/ft_printf.h"
# include "../libs/mlx_linux/mlx.h"

// Other libraries
#include <fcntl.h> // open
#include <stdbool.h> // bool

// Math libraries
# include <math.h>

# define COS_45 0.70710678118
# define SIN_45 sin(45)

# define COS_ARCTAN_ROOT2 0.5774
# define SIN_ARCTAN_ROOT2 0.8165

typedef struct s_coordinates{
   float x;
   float y;
   float z;
} t_coordinates;

typedef struct
{
    float x_iso;
    float y_iso;
} t_iso_coordinates;



typedef struct Node{
    
    t_coordinates coord;
    struct Node *next;
    t_iso_coordinates iso_coord;
} Node;


typedef struct bresenham_data{
    
    t_coordinates values;
    struct bresenham_data *next;
    int p_value;
    int dx;
    int dy;
    
} bresenham_data;




void	iso_coordinates(Node *head);

//Algorithm
void	bresenham_algorithm(int x1, int y1, int x2, int y2, void *mlx_connection, void *mlx_window);

//Max min
// int max_node_x(Node *head);
// int max_node_y(Node *head);
// int extract_x(t_coordinates coord);
typedef float (*CoordinateExtractor)(t_coordinates);
float extract_x(t_coordinates coord);
float extract_y(t_coordinates coord);
float max_node_coordinate(Node* head, CoordinateExtractor extractor);
float min_node_coordinate(Node* head, CoordinateExtractor extractor);




# endif