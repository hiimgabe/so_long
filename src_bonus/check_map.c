/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:06 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:21:58 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkcolumns(t_data *data)
{
	if (data->columns < 3)
	{
		ft_printf("%s", COLUMN_ERROR);
		ft_destroy(data);
		exit(0);
	}
}

void	ft_checklines(t_data *data)
{
	if (data->lines < 3)
	{
		ft_printf("%s", LINE_ERROR);
		ft_destroy(data);
		exit (0);
	}
	ft_checkcolumns(data);
}

void	ft_checkrectangle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->columns)
		{
			ft_printf("%s", RECTANGLE_ERROR);
			ft_destroy(data);
			exit (0);
		}
		else
			i++;
	}
	ft_checkchars(data);
}

void	ft_checkchars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == '1' || data->map[i][j] == '0' ||
				data->map[i][j] == 'P' || data->map[i][j] == 'E' ||
				data->map[i][j] == 'C' || data->map[i][j] == 'M' )
				j++;
			else
			{
				ft_printf("%s", CHARACTER_ERROR);
				ft_destroy(data);
			}
		}
		i++;
	}
	ft_checkwalls(data);
}

void	ft_checkwalls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] == '1' && data->map[data->lines - 1][i] == '1')
			i++;
		else
		{
			ft_printf("%s", WALLS_ERROR);
			ft_destroy(data);
		}
	}
	i = 1;
	while (i < data->lines - 1)
	{
		if (data->map[i][0] == '1' && data->map[i][data->columns - 1] == '1')
			i++;
		else
		{
			ft_printf("%s", WALLS_ERROR);
			ft_destroy(data);
		}
	}
	ft_playercoordinates(data);
}
