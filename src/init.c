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
	data->img_exit_closed = 0;
	data->img_exit_open = 0;
	data->moves = 0;
	data->score = 0;
	data->x = 0;
	data->y = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->fd = 0;
	data->map = 0;
	data->coin = 0;
	data->player = 0;
	data->exit = 0;
	data->columns = 0;
	data->lines = 0;
	data->map = 0;
}