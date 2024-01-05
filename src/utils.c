/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:47 by gamoreir          #+#    #+#             */
/*   Updated: 2024/01/05 16:44:34 by gabe             ###   ########.fr       */
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

int	ft_cntlines(t_data *data)
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

void	ft_playercoordinates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				data->player ++;
			}
			if (data->map[i][j] == 'C')
				data->coin ++;
			if (data->map[i][j] == 'E')
				ft_getexitcoords(data, i, j);
			j++;
		}
		i++;
	}
	ft_checkgamecomponents(data);
}

void	ft_getexitcoords(t_data *data, int i, int j)
{
	data->exit ++;
	data->e_x = j;
	data->e_y = i;
}

void	ft_drawimg(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, img, x * SIZE, y * SIZE);
}
