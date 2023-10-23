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

void	ft_checkgamecomponents(t_data *data)
{
	if (data->player != 1)
	{
		ft_printf("%s", PLAYER_ERROR);
		ft_destroy(data);
		exit(0);
	}
	else if (data->exit != 1)
	{
		ft_printf("%s", EXIT_ERROR);
		ft_destroy(data);
		exit(0);
	}
	else if (data->coin < 1)
	{
		ft_printf("%s", COIN_ERROR);
		ft_destroy(data);
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
		ft_printf("%s", PATH_ERROR);
		ft_clear_map2(data);
		ft_destroy(data);
	}
	else
		ft_clear_map2(data);
}
