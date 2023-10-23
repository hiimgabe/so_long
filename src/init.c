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

void	ft_initfirst(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->wall1 = 0;
	data->wall2 = 0;
	data->wall3 = 0;
	data->wall4 = 0;
	data->wall5 = 0;
	data->wall6 = 0;
	data->floor = 0;
	data->coin4 = 0;
	data->exit_closed3 = 0;
	data->w1 = 0;
	data->a1 = 0;
	data->s1 = 0;
	data->d1 = 0;
	ft_initsecond(data);
}

void	ft_initsecond(t_data *data)
{
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
	data->exit_state = 0;
	data->coin = 0;
	data->enemy = 0;
	data->map = 0;
	data->map_check = 0;
}
