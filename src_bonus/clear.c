/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:47 by gamoreir          #+#    #+#             */
/*   Updated: 2023/05/31 16:09:38 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(t_data *data)
{
	ft_clearfirst(data);
	exit(0);
}

void	ft_clearfirst(t_data	*data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall1);
	mlx_destroy_image(data->mlx_ptr, data->wall2);
	mlx_destroy_image(data->mlx_ptr, data->wall3);
	mlx_destroy_image(data->mlx_ptr, data->wall4);
	mlx_destroy_image(data->mlx_ptr, data->wall5);
	mlx_destroy_image(data->mlx_ptr, data->wall6);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->coin1);
	mlx_destroy_image(data->mlx_ptr, data->coin2);
	mlx_destroy_image(data->mlx_ptr, data->coin3);
	mlx_destroy_image(data->mlx_ptr, data->coin4);
	mlx_destroy_image(data->mlx_ptr, data->enemy1);
	mlx_destroy_image(data->mlx_ptr, data->enemy2);
	mlx_destroy_image(data->mlx_ptr, data->exit_closed1);
	mlx_destroy_image(data->mlx_ptr, data->exit_closed2);
	mlx_destroy_image(data->mlx_ptr, data->exit_closed3);
	mlx_destroy_image(data->mlx_ptr, data->exit_closed4);
	mlx_destroy_image(data->mlx_ptr, data->closed_to_open1);
	ft_clearsecond(data);
}

void	ft_clearsecond(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->closed_to_open2);
	mlx_destroy_image(data->mlx_ptr, data->closed_to_open3);
	mlx_destroy_image(data->mlx_ptr, data->closed_to_open4);
	mlx_destroy_image(data->mlx_ptr, data->exit_open1);
	mlx_destroy_image(data->mlx_ptr, data->exit_open2);
	mlx_destroy_image(data->mlx_ptr, data->w1);
	mlx_destroy_image(data->mlx_ptr, data->w2);
	mlx_destroy_image(data->mlx_ptr, data->a1);
	mlx_destroy_image(data->mlx_ptr, data->a2);
	mlx_destroy_image(data->mlx_ptr, data->s1);
	mlx_destroy_image(data->mlx_ptr, data->s2);
	mlx_destroy_image(data->mlx_ptr, data->d1);
	mlx_destroy_image(data->mlx_ptr, data->d2);
	mlx_destroy_image(data->mlx_ptr, data->bar);
	ft_clear_map(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	ft_clear_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	ft_clear_map2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_check[i])
		free(data->map_check[i++]);
	free(data->map_check);
}
