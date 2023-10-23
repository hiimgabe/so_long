/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:06 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:21:58 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_getspritesfirst(t_data *data, char *mapname)
{
	data->wall1 = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL1, &data->x, &data->y);
	data->wall2 = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL2, &data->x, &data->y);
	data->wall3 = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL3, &data->x, &data->y);
	data->wall4 = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL4, &data->x, &data->y);
	data->wall5 = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL5, &data->x, &data->y);
	data->wall6 = mlx_xpm_file_to_image
		(data->mlx_ptr, WALL6, &data->x, &data->y);
	data->floor = mlx_xpm_file_to_image
		(data->mlx_ptr, FLOOR, &data->x, &data->y);
	data->w1 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_W1, &data->x, &data->y);
	data->w2 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_W2, &data->x, &data->y);
	data->a1 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_A1, &data->x, &data->y);
	ft_getspritessecond(data, mapname);
}

void	ft_getspritessecond(t_data *data, char *mapname)
{
	data->a2 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_A2, &data->x, &data->y);
	data->s1 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_S1, &data->x, &data->y);
	data->s2 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_S2, &data->x, &data->y);
	data->d1 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_D1, &data->x, &data->y);
	data->d2 = mlx_xpm_file_to_image
		(data->mlx_ptr, PLAYER_D2, &data->x, &data->y);
	data->coin1 = mlx_xpm_file_to_image
		(data->mlx_ptr, COIN1, &data->x, &data->y);
	data->coin2 = mlx_xpm_file_to_image
		(data->mlx_ptr, COIN2, &data->x, &data->y);
	data->coin3 = mlx_xpm_file_to_image
		(data->mlx_ptr, COIN3, &data->x, &data->y);
	data->coin4 = mlx_xpm_file_to_image
		(data->mlx_ptr, COIN4, &data->x, &data->y);
	data->enemy1 = mlx_xpm_file_to_image
		(data->mlx_ptr, ENEMY1, &data->x, &data->y);
	data->enemy2 = mlx_xpm_file_to_image
		(data->mlx_ptr, ENEMY2, &data->x, &data->y);
	ft_getspritesthird(data, mapname);
}

void	ft_getspritesthird(t_data *data, char *mapname)
{
	data->exit_closed1 = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_CLOSED1, &data->x, &data->y);
	data->exit_closed2 = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_CLOSED2, &data->x, &data->y);
	data->exit_closed3 = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_CLOSED3, &data->x, &data->y);
	data->exit_closed4 = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_CLOSED4, &data->x, &data->y);
	data->closed_to_open1 = mlx_xpm_file_to_image
		(data->mlx_ptr, CLOSED_TO_OPEN1, &data->x, &data->y);
	data->closed_to_open2 = mlx_xpm_file_to_image
		(data->mlx_ptr, CLOSED_TO_OPEN2, &data->x, &data->y);
	data->closed_to_open3 = mlx_xpm_file_to_image
		(data->mlx_ptr, CLOSED_TO_OPEN3, &data->x, &data->y);
	data->closed_to_open4 = mlx_xpm_file_to_image
		(data->mlx_ptr, CLOSED_TO_OPEN4, &data->x, &data->y);
	data->exit_open1 = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_OPEN1, &data->x, &data->y);
	data->exit_open2 = mlx_xpm_file_to_image
		(data->mlx_ptr, EXIT_OPEN2, &data->x, &data->y);
	data->bar = mlx_xpm_file_to_image
		(data->mlx_ptr, BAR, &data->x, &data->y);
	ft_initmap(data, mapname);
}
