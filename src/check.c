/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
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
		ft_printf("ERROR: Not enough columns int the given map.\n");
		ft_clear(data);
		exit(0);
	}
}

void	ft_checklines(t_data *data)
{
	if (data->lines < 3)
	{
		ft_printf("ERROR: Not enough lines in the given map.\n");
		ft_clear(data);
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
			ft_printf("ERROR: Given map isn't a rectangle.\n");
			ft_clear(data);
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
				data->map[i][j] == 'P' || data->map[i][j] == 'M' ||
				data->map[i][j] == 'E' || data->map[i][j] == 'C')
				j++;
			else
			{
				ft_printf("ERROR: Invalid characters found on the map.\n");
				ft_clear(data);
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
			ft_printf("ERROR: Map walls are invalid.");
			ft_clear(data);
		}
	}
	i = 1;
	while (i < data->lines - 1)
	{
		if (data->map[i][0] == '1' && data->map[i][data->columns - 1] == '1')
			i++;
		else
		{
			ft_printf("ERROR: Map walls are invalid.");
			ft_clear(data);
		}
	}
	ft_playercoordinates(data);
}

void	ft_checkgamecomponents(t_data *data)
{
	if (data->player != 1)
	{
		ft_printf("ERROR: Wrong number of Player in the given map.\n");
		ft_clear(data);
		exit(0);
	}
	else if (data->exit != 1)
	{
		ft_printf("ERROR: Wrong number of Exit in the given map.\n");
		ft_clear(data);
		exit(0);
	}
	else if (data->coin < 1)
	{
		ft_printf("ERROR: Wrong number of Collectibles in the given map.\n");
		ft_clear(data);
		exit(0);
	}
	ft_checkpath(data);
}

void	ft_dupmap(t_data *data)
{
	int	i;

	i = 0;
	data->map_check = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < data->lines)
	{
		data->map_check[i] = ft_strdup(data->map[i]);
		i++;
	}
}

int	ft_floodfill(t_data *data, char **map, int x, int y)
{
	static int	e;
	static int	c;

	if (x < 0 || y < 0 || x > data->columns
		|| y > data->lines || map[y][x] == '1'
		|| map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		e++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	ft_floodfill(data, map, x + 1, y);
	ft_floodfill(data, map, x - 1, y);
	ft_floodfill(data, map, x, y + 1);
	ft_floodfill(data, map, x, y - 1);
	if (e == 1 && c == data->coin)
		return (1);
	else
		return (0);
}

void	ft_checkpath(t_data *data)
{
	ft_dupmap(data);
	if (ft_floodfill(data, data->map_check, data->p_x, data->p_y) != 1)
	{
		ft_printf("ERROR: Invalid map path.\n");
		ft_clear_map2(data);
		ft_clear(data);
	}
	else
		ft_clear_map2(data);
}
