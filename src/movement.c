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

int	ft_moveplayer(t_data *data, int y, int x, char key)
{
	if (data->map[y][x] == '0')
	{
		if (key == 'W')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_w, x * SIZE, y * SIZE);
		}
		else if (key == 'A')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_a, x * SIZE, y * SIZE);
		}
		else if (key == 'S')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_s, x * SIZE, y * SIZE);
		}
		else if (key == 'D')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_d, x * SIZE, y * SIZE);
		}
		data->map[data->player->y][data->player->x] = '0';
		data->map[y][x] = '0';
		data->player->y = y;
		data->player->x = x;
		data->moves ++;
		return (1);
	}
	else if(data->map[y][x] == 'C')
	{
		if (key == 'W')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_w, x * SIZE, y * SIZE);
		}
		else if (key == 'A')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_a, x * SIZE, y * SIZE);
		}
		else if (key == 'S')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_s, x * SIZE, y * SIZE);
		}
		else if (key == 'D')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->player->x * SIZE, data->player->y * SIZE);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player->img_d, x * SIZE, y * SIZE);
		}
		data->map[data->player->y][data->player->x] = '0';
		data->map[y][x] = '0';
		data->player->y = y;
		data->player->x = x;
		data->moves ++;
		data->score ++;
		if (data->score == data->c)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit_open, data->e_x * SIZE, data->e_y * SIZE);
		return (1);
	}
	else if (data->map[y][x] == 'E' && data->score == data->c)
	{
		printf("Congratulations, you collected everything and escaped in %d moves!\n", data->moves);
		ft_clear(data);
	}
	else if (data->map[y][x] == 'M')
	{
		printf("You died, score: %d\n", data->score);
		ft_clear(data);
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	int	result;

	result = 0;
	if (keysym == 65307)
		ft_clear(data);
	if (keysym == 119)
		result = ft_moveplayer(data, data->player->y - 1, data->player->x, 'W');
	if (keysym == 97)
		result = ft_moveplayer(data, data->player->y, data->player->x - 1, 'A');
	if (keysym == 115)
		result = ft_moveplayer(data, data->player->y + 1, data->player->x, 'S');
	if (keysym == 100)
		result = ft_moveplayer(data, data->player->y, data->player->x + 1, 'D');
	if (result == 1)
		ft_printf("Move number: %d\nScore: %d out of %d\nKey: %d\n", data->moves, data->score, data->c, keysym);
	return (0);
}
