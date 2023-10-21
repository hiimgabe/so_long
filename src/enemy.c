/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:06 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:21:58 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemysprite(t_data *data, int y, int x, char key)
{
	if (key == 'W')
		ft_drawimg(data, data->enemy1, x, y);
	else if (key == 'A')
		ft_drawimg(data, data->enemy2, x, y);
	else if (key == 'S')
		ft_drawimg(data, data->enemy1, x, y);
	else if (key == 'D')
		ft_drawimg(data, data->enemy2, x, y);
}

void	ft_enemyanim(t_data *data)
{
	static int	i;
	static int	j;
	static int	k;

	if (i == 2)
		i = 0;
	k = 0;
	while (k < data->lines)
	{
		j = 0;
		while (data->map[k][j] != '\n' && data->map[k][j] != '\0')
		{
			if (data->map[k][j] == 'M' && i == 0)
				ft_drawimg(data, data->exit_open1, j, k);
			else if (data->map[k][j] == 'M' && i == 1)
				ft_drawimg(data, data->exit_open2, j, k);
			j++;
		}
		k++;
	}
	i++;
}

int	ft_moveenemy(t_data *data, int y, int x, char key)
{
	if (data->map[y][x] == '0')
	{
		ft_enemysprite(data, y, x, key);
		data->map[y][x] = 'M';
		return (1);
	}
	else if (data->map[y][x] == 'P')
	{
		printf("The enemy caught you! :( score: %d\n", data->score);
		ft_clear(data);
	}
	return (0);
}

void	ft_movecheck(t_data *data, int random, int y, int x)
{
	int	i;

	i = 0;
	if (random == 0)
		i = ft_moveenemy(data, y - 1, x, 'W');
	else if (random == 1)
		i = ft_moveenemy(data, y, x - 1, 'A');
	else if (random == 2)
		i = ft_moveenemy(data, y + 1, x, 'S');
	else if (random == 3)
		i = ft_moveenemy(data, y, x + 1, 'D');
	if (i == 1)
	{
		data->map[y][x] = '0';
		ft_drawimg(data, data->floor, x, y);
	}
}

void	ft_enemy(t_data *data)
{
	int	random;
	int	x;
	int	y;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == 'M')
			{
				random = rand() % 4;
				ft_movecheck(data, random, y, x);
				if (random == 3)
					x++;
				if (random == 2)
					y++;
			}
			x++;
		}
		y++;
	}
}
