/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/30 14:11:27 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

// #include <stdio.h>

int main(void)
{
    Node *head;
    
    head = NULL;
    head = read_map(head);    
    iso_copy(head);
    rotate_z_45(head);
    rotate_x_arctan_root2(head);
    get_connections(head);    
    draw(head);
    return (0);
}
