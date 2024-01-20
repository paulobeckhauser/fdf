/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 23:29:52 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"



int main(int argc, char **argv)
{
    t_map *s_map;
    mlx_t *mlx;
    mlx_image_t *img;


    if (argc != 2 || check_map_format(argv[1]))
        return (print_return("Wrong file format or file does not exist\n", 1));
    s_map = map_read(argv[1]);
        if (!(s_map))
            return (print_return("File has no content or bad format\n", 1));
    mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "FDF", true);
    img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    mlx_image_to_window(mlx, img, 0, 0);
    render(s_map, img);
    task_mlx(mlx);
    clean_data(s_map);
    return (0);

    

    

    

   return (0);
}
