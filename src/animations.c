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

void ft_player_anim(t_data *data, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, data->x * SIZE, data->y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w1, x * SIZE, y * SIZE);
}