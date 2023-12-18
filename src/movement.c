/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:47 by gamoreir          #+#    #+#             */
/*   Updated: 2023/12/18 11:48:51 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_playermovecheck(t_data *data, int y, int x, char key)
{
	if (key == 'W')
		ft_drawimg(data, data->w1, x, y);
	else if (key == 'A')
		ft_drawimg(data, data->a1, x, y);
	else if (key == 'S')
		ft_drawimg(data, data->s1, x, y);
	else if (key == 'D')
		ft_drawimg(data, data->d1, x, y);
}

int	ft_moveplayer(t_data *data, int y, int x, char key)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C' || (data->map[y][x] == 'E' && !(data->score == data->coin)))
	{
		if (data->p_y == data->e_y && data->p_x == data->e_x)
		{
			ft_drawimg(data, data->exit_closed3, data->p_x, data->p_y);
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
		ft_printf("Moves: %d\n", data->moves);
	}
	return (0);
}
/*
ft_printf("Move number: %d\nScore: %d out of %d\nKey:
 %d\n", data->moves, data->score, data->coin, keysym);
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
*/