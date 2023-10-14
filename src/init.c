/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:06 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:21:58 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->img_wall = 0;
	data->img_floor = 0;
	data->img_coin = 0;
	data->img_enemy = 0;
	data->img_player = 0;
	data->img_exit1 = 0;
	data->img_exit2 = 0;
	data->img_exit3 = 0;
	data->img_exit4 = 0;
	data->img_w1 = 0;
	data->img_w2 = 0;
	data->img_a1 = 0;
	data->img_a2 = 0;
	data->img_s1 = 0;
	data->img_s2 = 0;
	data->img_d1 = 0;
	data->img_d2 = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->x = 0;
	data->y = 0;
	data->moves = 0;
	data->score = 0;
	data->fd = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->columns = 0;
	data->lines = 0;
	data->player = 0;
	data->exit = 0;
	data->coin = 0;
	data->enemy = 0;
	data->map = 0;
	data->map_check = 0;
}