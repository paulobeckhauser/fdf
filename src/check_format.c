/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:22:40 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/03 14:02:20 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_format(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*format;

	i = 0;
	len = ft_strlen(str);
	format = (char *)malloc((len + 1) * sizeof(char));
	j = 4;
	format[j] = '\0';
	while (str[len - 1] && i < 4)
	{
		j--;
		format[j] = str[len - 1];
		i++;
		len--;
	}
	if (ft_strncmp(format, ".fdf", 4) == 0)
		return (0);
	else
	{
		ft_printf("Error in the format of the file\n");
		return (1);
	}
}
