/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:47 by gamoreir          #+#    #+#             */
/*   Updated: 2023/12/18 11:41:55 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_playermovecheck(t_data *data, int y, int x, char key)
{
	static int	state;

	if (state == 0)
		state = 1;
	else if (state == 1)
		state = 0;
	if (key == 'W' && state == 1)
		ft_drawimg(data, data->w1, x, y);
	else if (key == 'W' && state == 0)
		ft_drawimg(data, data->w2, x, y);
	else if (key == 'A' && state == 1)
		ft_drawimg(data, data->a1, x, y);
	else if (key == 'A' && state == 0)
		ft_drawimg(data, data->a2, x, y);
	else if (key == 'S' && state == 1)
		ft_drawimg(data, data->s1, x, y);
	else if (key == 'S' && state == 0)
		ft_drawimg(data, data->s2, x, y);
	else if (key == 'D' && state == 1)
		ft_drawimg(data, data->d1, x, y);
	else if (key == 'D' && state == 0)
		ft_drawimg(data, data->d2, x, y);
}

int	ft_moveplayer(t_data *data, int y, int x, char key)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C' || (data->map[y][x] == 'E' && !(data->score == data->coin)))
	{
		if (data->p_y == data->e_y && data->p_x == data->e_x)
		{
			ft_drawimg(data, data->floor, data->p_x, data->p_y);
			ft_playermovecheck(data, y, x, key);
			data->map[data->p_y][data->p_x] = 'E';
			data->map[y][x] = 'P';
			data->p_y = y;
			data->p_x = x;
			data->moves ++;
		}
		ft_drawimg(data, data->floor, data->p_x, data->p_y);
		ft_playermovecheck(data, y, x, key);
		if (data->map[y][x] == 'C')
			data->score ++;
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = 'P';
		data->p_y = y;
		data->p_x = x;
		data->moves ++;
		return (1);
	}
	else if (data->map[y][x] == 'E')
	{
		if (data->score == data->coin)
		{
			printf("Congratulations, you escaped in %d moves!\n", data->moves);
			ft_destroy(data);
		}
		ft_drawimg(data, data->floor, data->p_x, data->p_y);
		ft_playermovecheck(data, y, x, key);
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = 'P';
		data->p_y = y;
		data->p_x = x;
		data->moves ++;
	}
	else if (data->map[y][x] == 'M')
	{
		printf("You died, score: %d\n", data->score);
		ft_destroy(data);
	}
	return (0);
}

void	ft_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->moves);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bar,
		(data->columns / 2) * SIZE + 50, data->lines * SIZE);
	mlx_string_put(data->mlx_ptr, data->win_ptr, (data->columns / 2)
		* SIZE + 50, data->lines * SIZE + 15, 0xFFFFFF, moves);
	free (moves);
}

int	handle_input(int keysym, t_data *data)
{
	int	result;

	result = 0;
	if (keysym == 65307)
		ft_destroy(data);
	if (keysym == 119)
		result = ft_moveplayer(data, data->p_y - 1, data->p_x, 'W');
	if (keysym == 97)
		result = ft_moveplayer(data, data->p_y, data->p_x - 1, 'A');
	if (keysym == 115)
		result = ft_moveplayer(data, data->p_y + 1, data->p_x, 'S');
	if (keysym == 100)
		result = ft_moveplayer(data, data->p_y, data->p_x + 1, 'D');
	if (result == 1)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, (data->columns / 2)
			* SIZE, data->lines * SIZE + 15, 0xFFFFFF, "Moves: ");
		ft_printf("Move number: %d\nScore: %d out of %d\nKey:%d\n", data->moves, data->score, data->coin, keysym);
		ft_printf("%s\n", data->map[0]);
		ft_printf("%s\n", data->map[1]);
		ft_printf("%s\n", data->map[2]);
		ft_printf("%s\n", data->map[3]);
		ft_printf("%s\n", data->map[4]);
		ft_printf("%s\n", data->map[5]);
		ft_printf("%s\n", data->map[6]);
		ft_printf("%s\n", data->map[7]);
		ft_printf("%s\n", data->map[8]);
		ft_printf("%s\n", data->map[9]);
		ft_printf("data->exit_state = %d\n", data->exit_state);
		ft_printf("data->lines = %d\n", data->lines);
		ft_printf("data->columns = %d\n", data->columns);
		ft_moves(data);
	}
	return (0);
}
/*
*/