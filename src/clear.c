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

int	ft_clear(t_data	*data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img_floor);
	mlx_destroy_image(data->mlx_ptr, data->img_coin1);
	mlx_destroy_image(data->mlx_ptr, data->img_coin2);
	mlx_destroy_image(data->mlx_ptr, data->img_coin3);
	mlx_destroy_image(data->mlx_ptr, data->img_coin4);
	mlx_destroy_image(data->mlx_ptr, data->img_w1);
	mlx_destroy_image(data->mlx_ptr, data->img_a1);
	mlx_destroy_image(data->mlx_ptr, data->img_s1);
	mlx_destroy_image(data->mlx_ptr, data->img_d1);
	mlx_destroy_image(data->mlx_ptr, data->img_exit_closed1);
	mlx_destroy_image(data->mlx_ptr, data->img_exit_closed2);
	mlx_destroy_image(data->mlx_ptr, data->img_exit_closed3);
	mlx_destroy_image(data->mlx_ptr, data->img_exit_closed4);
	ft_clear_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
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