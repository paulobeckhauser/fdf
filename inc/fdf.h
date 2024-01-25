/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:10:31 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/25 20:25:59 by pabeckha         ###   ########.fr       */
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

# endif