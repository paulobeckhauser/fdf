/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:03:49 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/25 19:09:00 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libs/mlx_linux/mlx.h"

int main(void)
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Pixel");

    mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);
    mlx_loop(mlx);
}