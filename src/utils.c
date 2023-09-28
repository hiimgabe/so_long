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

int	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_initdata(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->img_wall = 0;
	data->img_floor = 0;
	data->img_coin = 0;
	data->img_enemy = 0;
	data->img_player = 0;
	data->img_exit_closed = 0;
	data->img_exit_open = 0;
	data->player->img_w1 = 0;
	data->player->img_a2 = 0;
	data->player->img_s1 = 0;
	data->player->img_d1 = 0;
	data->moves = 0;
	data->score = 0;
	data->x = 0;
	data->y = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->fd = 0;
	data->columns = 0;
	data->lines = 0;
	data->map = 0;
}

int	ft_cntlines(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(data->fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free(str);
	return (i);
}

void	ft_playercoordinates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if(data->map[i][j] == 'P')
			{
				data->player->x = j;
				data->player->y = i;
				data->p ++;
			}
			if (data->map[i][j] == 'C')
				data->c++;
			if (data->map[i][j] == 'E')
			{
				data->e++;
				data->e_x = j;
				data->e_y = i;
			}
			j++;
		}
		i++;
	}
}
