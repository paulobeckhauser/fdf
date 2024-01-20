/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:10:18 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/20 17:21:59 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"


static int validate_file(const char *argv)
{
    int fd;
    
    fd = open(argv, O_RDONLY);
    if (fd < 0)
        return (1);
    close(fd);
    return (0);
}

int check_map_format(const char *argv)
{
    int map_name_len;
    int format_len;
    const char *format;
    int start_position;
    
    
    map_name_len = ft_strlen(argv);
    format = ".fdf";
    format_len = ft_strlen(format);
    if (map_name_len >= format_len)
    {
        start_position = map_name_len - format_len;
        if (!(ft_strncmp(argv + start_position, format, format_len)))
        {
            if (!(validate_file(argv)))
                return (0);
        }
    }
    return (1);
}
