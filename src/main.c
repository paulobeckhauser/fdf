/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:14:39 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/03 13:49:37 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_node	*head;
	int		prog_return;

	prog_return = 0;
	if (argc == 2)
	{
		prog_return = check_format(argv[1]);
		if (prog_return == 1)
			return (prog_return);
		head = NULL;
		head = read_map(head, argv[1]);
		iso_copy(head);
		rotate_z_45(head);
		rotate_x_arctan_root2(head);
		get_connections(head);
		draw(head);
	}
	else
	{
		ft_printf("Too much or too low arguments\n");
		prog_return = 1;
	}
	return (prog_return);
}
