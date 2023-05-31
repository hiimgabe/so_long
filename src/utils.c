/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:47 by gamoreir          #+#    #+#             */
/*   Updated: 2023/05/31 16:09:38 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_initdata(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->img_wall = 0;
	data->x = 0;
	data->y = 0;
	data->fd = 0;
	data->columns = 0;
	data->rows = 0;
	data->map = 0;
}

int	ft_cntrows(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(data->fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free(str);
	return (i);
}
