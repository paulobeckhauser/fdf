/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollock_paiting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:11:02 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/25 19:36:43 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libs/mlx_linux/mlx.h"

int main(void)
{
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init(); // start the "machine"

    mlx_window = mlx_new_window(mlx_connection, 500, 500, "My 1* window");
    
    for (int i = 1; i < 100; ++i)
    {
        mlx_pixel_put(mlx_connection, mlx_window, -50 + i, 250, 0xff0000);
        
    }

    
    mlx_loop(mlx_connection);
    


}