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

void	ft_drawimg(t_data *data, int y, int x, char key)
{
	if (key == 'W')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w1, x * SIZE, y * SIZE);
		else if (key == 'A')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_a1, x * SIZE, y * SIZE);
		else if (key == 'S')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_s1, x * SIZE, y * SIZE);
		else if (key == 'D')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_d1, x * SIZE, y * SIZE);
}

int	ft_moveplayer(t_data *data, int y, int x, char key)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->p_x * SIZE, data->p_y * SIZE);
		ft_drawimg(data, y, x, key);
		if (data->map[y][x] == 'C')
			data->score ++;
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = 'P';
		data->p_y = y;
		data->p_x = x;
		data->moves ++;
		return (1);
	}
	else if (data->map[y][x] == 'E' && data->score == data->coin)
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
		result = ft_moveplayer(data, data->y - 1, data->x, 'W');
	if (keysym == 97)
		result = ft_moveplayer(data, data->y, data->x - 1, 'A');
	if (keysym == 115)
		result = ft_moveplayer(data, data->y + 1, data->x, 'S');
	if (keysym == 100)
		result = ft_moveplayer(data, data->y, data->x + 1, 'D');
	if (result == 1)
		ft_printf("Move number: %d\nScore: %d out of %d\nKey: %d\n", data->moves, data->score, data->coin, keysym);
	return (0);
}
