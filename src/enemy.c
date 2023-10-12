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

void ft_enemysprite(t_data *data, int y, int x, char key)
{
	if (key == 'W')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_enemy, x * SIZE, y * SIZE);
	else if (key == 'A')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_enemy, x * SIZE, y * SIZE);
	else if (key == 'S')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_enemy, x * SIZE, y * SIZE);
	else if (key == 'D')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_enemy, x * SIZE, y * SIZE);
}

int	ft_moveenemy(t_data *data, int	y, int x, char key)
{
	if (data->map[y][x] == '0')
	{
		ft_enemysprite(data, y, x, key);
		data->map[y][x] = 'M';
		return (1);
	}
	else if (data->map[y][x] == 'P')
	{
		printf("You died, score: %d\n", data->score);
		ft_clear(data);
	}
	return (0);
}

void	ft_movecheck(t_data *data, int random, int	y, int x)
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
		data->map[y][x] = mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, x * SIZE, y * SIZE);
	}
}

void	ft_enemy(t_data *data)
{
	static int	random;
	static int	x;
	static int	y;

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
			}
			x++;
		}
		y++;
	}
}