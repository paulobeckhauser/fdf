/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:10:31 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/01 22:51:27 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Made libraries
# include "../libs/libft/inc/ft_printf.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"
# include "../libs/mlx_linux/mlx.h"

# define MIN_FLOAT 1.17549435e-38F
# define MAX_FLOAT 3.40282347e+38F

// Other libraries
# include <fcntl.h>   // open
# include <stdbool.h> // bool

// Math libraries
# include <math.h>

# define WINDOW_WITDH 1920
# define WINDOW_HEIGHT 1080
# define MARGIN 10.0

typedef struct s_coordinates
{
	float			x;
	float			y;
	float			z;
}					t_coordinates;

typedef struct Node
{
	t_coordinates	coord;
	struct Node		*next;
	struct Node		*prev;

	t_coordinates	iso_coord;

	t_coordinates	up;
	t_coordinates	down;
	t_coordinates	left;
	t_coordinates	right;

}					t_node;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

void				iso_coordinates(t_node *head);

// Algorithm
// void				bresenham_algorithm(int x1, int y1, int x2, int y2,
// 						void *image);
void bresenham_algorithm(t_coordinates iso_coord, int x2, int y2, void *img);
// void bresenham_algorithm(t_node *head, bool use_down, void *img);

typedef float		(*t_coordinate_extractor)(t_coordinates);
float				extract_x(t_coordinates coord);
float				extract_y(t_coordinates coord);
float				max_node_coordinate(t_node *head,
						t_coordinate_extractor extractor);
float				min_node_coordinate(t_node *head,
						t_coordinate_extractor extractor);

// connections
void				set_coordinates_to_nan(t_coordinates *coord);
void				get_connections(t_node *head);

// draw
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Rotation
void				iso_copy(t_node *head);
void				rotate_z_45(t_node *head);
void				rotate_x_arctan_root2(t_node *head);

// read map
t_node				*read_map(t_node *head, char *map_name);

// draw
void				draw(t_node *head);

#endif