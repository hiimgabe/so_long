/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:06 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:21:58 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animations(t_data *data)
{
	static int	i;

	if (data->score == data->coin && data->exit_state == 0)
		data->exit_state = 1;
	i++;
	if (i == 1)
		ft_animcoin(data);
	else if (i == 2)
		ft_enemy(data);
	else if (i == 3 && data->exit_state == 0)
		ft_animexitclosed(data);
	else if (i == 3 && data->exit_state == 1)
		ft_animexitclosetoopen(data);
	else if (i == 3 && data->exit_state == 2)
		ft_animexitopen(data);
	else if (i > 3)
		i = 0;
	usleep(95550);
	return (1);
}

void	ft_drawcoin(t_data *data, int k, int j, int i)
{
	if (data->map[k][j] == 'C' && i == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_coin1, j * SIZE, k * SIZE);
	else if (data->map[k][j] == 'C' && i == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_coin2, j * SIZE, k * SIZE);
	else if (data->map[k][j] == 'C' && i == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_coin3, j * SIZE, k * SIZE);
	else if (data->map[k][j] == 'C' && i == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_coin4, j * SIZE, k * SIZE);
}

void	ft_animcoin(t_data *data)
{
	static int	i;
	static int	j;
	static int	k;

	if (i == 4)
		i = 0;
	k = 0;
	while (k < data->lines)
	{
		j = 0;
		while (data->map[k][j] != '\n' && data->map[k][j] != '\0')
		{
			ft_drawcoin(data, k, j, i);
			j++;
		}
		k++;
	}
	i++;
}

void	ft_animexitclosed(t_data *data)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (i == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit_closed1, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit_closed2, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit_closed3, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit_closed4, data->e_x * SIZE, data->e_y * SIZE);
	i++;
}

void	ft_animexitopen(t_data *data)
{
	static int	i;

	if (i == 3)
		i = 0;
	if (i == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit_open1, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit_open2, data->e_x * SIZE, data->e_y * SIZE);
	i++;
}

void	ft_animexitclosetoopen(t_data *data)
{
	static int	i;

	if (i == 5)
		i = 0;
	if (i == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_closed_to_open1, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_closed_to_open2, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_closed_to_open3, data->e_x * SIZE, data->e_y * SIZE);
	else if (i == 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_closed_to_open4, data->e_x * SIZE, data->e_y * SIZE);
		data->exit_state = 2;
	}
	i++;
}
