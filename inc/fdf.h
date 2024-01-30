/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:10:31 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/30 16:29:20 by pabeckha         ###   ########.fr       */
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

// # define M_PI 3.14159265358979323846
# define WINDOW_WITDH 1920
# define WINDOW_HEIGHT 1080

# define COS_45 cos(45 * (M_PI / 180.0))
# define SIN_45 sin(45 * (M_PI / 180.0))

# define COS_35 cos(54.74 * (M_PI / 180.0))
# define SIN_35 sin(54.74 * (M_PI / 180.0))


// # define COS_ARCTAN_ROOT2 cos(atan(sqrt(2)))
// # define SIN_ARCTAN_ROOT2 sin(atan(sqrt(2)))

typedef struct s_coordinates{
   float x;
   float y;
   float z;
} t_coordinates;

// typedef struct
// {
//     float x_iso;
//     float y_iso;
//     float z_iso;
// } t_iso_coordinates;



typedef struct Node{
    
    t_coordinates coord;
    struct Node *next;
    struct Node *prev;
    
    t_coordinates iso_coord;
    
    t_coordinates up;
    t_coordinates down;
    t_coordinates left;
    t_coordinates right;
    
    // t_iso_coordinates up;
    // t_iso_coordinates down;
    // t_iso_coordinates left;
    // t_iso_coordinates right;
} Node;


// typedef struct s_node {
//     int z;
//     unsigned int color;
// }   t_node;

// t_node **fdf;


typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;



// typedef struct bresenham_data{
    
//     t_coordinates values;
//     struct bresenham_data *next;
//     int p_value;
//     int dx;
//     int dy;
    
// } bresenham_data;




void	iso_coordinates(Node *head);

//Algorithm
void bresenham_algorithm(int x1, int y1, int x2, int y2, void *image) ;

//Max min
// int max_node_x(Node *head);
// int max_node_y(Node *head);
// int extract_x(t_coordinates coord);
typedef float (*CoordinateExtractor)(t_coordinates);
float extract_x(t_coordinates coord);
float extract_y(t_coordinates coord);
float max_node_coordinate(Node* head, CoordinateExtractor extractor);
float min_node_coordinate(Node* head, CoordinateExtractor extractor);

//connections
void set_coordinates_to_nan(t_coordinates *coord);
void	get_connections(Node *head);

//draw
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Rotation
void iso_copy(Node *head);
void rotate_z_45(Node *head);
void rotate_x_arctan_root2(Node *head);


// read map
Node	*read_map(Node *head);

//draw
void draw(Node *head);


# endif