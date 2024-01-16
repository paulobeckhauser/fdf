/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:31:31 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/16 14:31:36 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int check_windows_size(char *width, char *height)
{
    size_t count;

    count = 0;
    while (width[count])
    {
        if (ft_isdigit(width[count]) == 0)
        {
            ft_printf("Error: Wrong size of windows\n");
            exit (0);
        }
        count++;
    }
}


int check_the_extension(char *name_of_map)
{
    int len;

    len = ft_strlen(name_of_map);
    if (len < 4)
    {
        ft_printf("map name is too short\n");
        return (0);
    }
    if (ft_strncmp(name_of_map + len - 4, ".fdf", 4) == 0)
    {
        ft_printf("\033[1;32mGood file extension\033[0m\n");
        return (0);
    }
    ft_printf("Error: The file is not a .fdf file\n");
    return (1);
}



int main(int argc, char **argv)
{
    t_point *head
    t_date info_map;
    int flag;

    head = NULL;
    info_map.width = DEFAULT_WIDTH;
    info_map.height = DEFAULT_HEIGHT;

    if (argc < 2 || argc > 4 || argc == 3)
        return(ft_printf("%sNot enough, or too much?%s\n", RED, RESET));
    if (argc == 4)
    {
        if (check_windows_size(argv[2], argv[3]))
        {
            info_map.width = ft_atoi(argv[2]);
            info_map.height = ft_atoi(argv[3]);
            check_if_windows(&info_map);
        }
        flag = (check_the_extension(argv[1]) + check_the_map(argv[1], &head));
        if (flag != 0)
            exit (0);
        info.map
    }
}