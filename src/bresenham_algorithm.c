/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:03:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/29 22:20:06 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"
# include <stdio.h>

// typedef struct s_data
// {
//     void *img;
//     char *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
// }   t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// bresenham_algorithm(571, 571, 500, 641, &img);

// void bresenham_algorithm(int x1, int y1, int x2, int y2, void *img) 
// {
//     int dx, dy, x, y, xend, yend, p, two_dy, two_dy_dx, two_dx, two_dx_dy;

//     dx = abs(x2 - x1);
//     dy = abs(y2 - y1);
//     two_dy = 2 * dy;
//     two_dx = 2 * dx;

//     if (dx > dy) 
//     {
//         p = two_dy - dx;
//         two_dy_dx = two_dy - two_dx;

//         if (x1 > x2) {
//             x = x2;
//             y = y2;
//             xend = x1;
//         } else {
//             x = x1;
//             y = y1;
//             xend = x2;
//         }
        
// 		my_mlx_pixel_put(img, x, y, 0x00FF0000);

//         while (x < xend) 
//         {
//             x++;
//             if (p < 0) {
//                 p += two_dy;
//             } else {
//                 if (y1 > y2) {
//                     y--;
//                 } else {
//                     y++;
//                 }
//                 p += two_dy_dx;
//             }
//             my_mlx_pixel_put(img, x, y, 0x00FF0000);
//         }
//     } 
//     else {
//         p = two_dx - dy;
//         two_dx_dy = two_dx - two_dy;

//         if (y1 > y2) {
//             x = x2;
//             y = y2;
//             yend = y1;
//         } else {
//             x = x1;
//             y = y1;
//             yend = y2;
//         }
//         my_mlx_pixel_put(img, x, y, 0x00FF0000);


//         while (y < yend) {
//             y++;
//             if (p < 0) {
//                 p += two_dx;
//             } else {
//                 if (x1 > x2) {
//                     x--;
//                 } else {
//                     x++;
//                 }
//                 p += two_dx_dy;
//             }
//             my_mlx_pixel_put(img, x, y, 0x00FF0000);
//         }
//     }
// }

void bresenham_algorithm(int x1, int y1, int x2, int y2, void *img) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    // int sx = (x1 < x2) ? 1 : -1;
    // int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int sx;
    int sy;
    if (x1 < x2)
        sx = 1;
    else
        sx = -1;
    if (y1 < y2)
        sy = 1;
    else
        sy = -1;
    while(1) {
        my_mlx_pixel_put(img, x1, y1, 0x00FF0000);

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}



// int main(void)
// {
// 	t_data img;
//     void *mlx_connection;
//     void *mlx_window;

//     mlx_connection = mlx_init();

//     mlx_window = mlx_new_window(mlx_connection, 1000, 1000, "fdf");
//     img.img = mlx_new_image(mlx_connection, 1000, 1000);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     // my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 501, 501, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 502, 502, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 503, 503, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 504, 504, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 505, 505, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 506, 506, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 507, 507, 0x00FF0000);
// 	// my_mlx_pixel_put(&img, 508, 508, 0x00FF0000);
//     // bresenham_algorithm(100, 100, 800, 500, &img);
//     // bresenham_algorithm(0, 0, 500, 500, &img);
//     // bresenham_algorithm(500, 500, 1000, 1000, &img);
//     // bresenham_algorithm(100, 100, 800, 500, &img);
//     // bresenham_algorithm(100, 100, 800, 500, &img);
//     // bresenham_algorithm(100, 100, 800, 500, &img);
    

//     // bresenham_algorithm(0, 0, 500, 641, &img);
    
//     bresenham_algorithm(0, 0, 571, 571, &img);
//     bresenham_algorithm(100, 0, 571, 571, &img);
//     bresenham_algorithm(0, 100, 571, 571, &img);
//     bresenham_algorithm(571, 571, 500, 641, &img);

// // 	// bresenham_algorithm(100, 100, 800, 500, mlx_connection, mlx_window);
// // 	// // bresenham_algorithm(800, 500, 100, 100, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(500, 500, 0, 0, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(500, 500, 1000, 0, mlx_connection, mlx_window);

// // 	// bresenham_algorithm(500, 500, 0, 0, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(0, 0, 500, 500, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(500, 500, 500, 0, mlx_connection, mlx_window);
// // 	bresenham_algorithm(1000, 0, 500, 500, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(500, 500, 1000, 0, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(500, 500, 1000, 500, mlx_connection, mlx_window);
// // 	// bresenham_algorithm(500, 500, 1000, 1000, mlx_connection, mlx_window);

//     mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);

//     mlx_loop(mlx_connection);
//     return (0);
// }