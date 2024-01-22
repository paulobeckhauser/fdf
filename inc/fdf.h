/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:10:31 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/21 15:40:14 by pabeckha         ###   ########.fr       */
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

# define SCREEN_WIDTH 1300
# define SCREEN_HEIGHT 900
# define COS_30 0.86602540378
# define SIN_30 0.5


typedef struct s_coordinate
{
    float x;
    float y;
    float z;
}   t_coordinates;

typedef struct s_map
{
    t_coordinates *s_coordinate;
    struct s_map *next;
    int width;
    int height;
    float scale;
    
    
    
}   t_map;

int print_return(char *str, int ret);
int check_map_format(const char *argv);
t_map *insert_node(t_map *head, t_map *s_list);
t_map *new_node(int x, int y, int z);

//cleaning
void clean_structure(t_map *s_map);
void clean_split(char **split_result);
void clean_matrix(float **map_matrix);


# endif