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

int	ft_moveplayer(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->p_x * SIZE, data->p_y * SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, x * SIZE, y * SIZE);
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = '0';
		data->p_y = y;
		data->p_x = x;
		data->moves ++;
		return (1);
	}
	else if(data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->p_x * SIZE, data->p_y * SIZE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, x * SIZE, y * SIZE);
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = '0';
		data->p_y = y;
		data->p_x = x;
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
		result = ft_moveplayer(data, data->p_y - 1, data->p_x);
	if (keysym == 97)
		result = ft_moveplayer(data, data->p_y, data->p_x - 1);
	if (keysym == 115)
		result = ft_moveplayer(data, data->p_y + 1, data->p_x);
	if (keysym == 100)
		result = ft_moveplayer(data, data->p_y, data->p_x + 1);
	if (result == 1)
		ft_printf("Move number: %d\n", data->moves);
	return (0);
}
