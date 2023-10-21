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
	usleep(90000);
	return (1);
}

void	ft_drawcoin(t_data *data, int k, int j, int i)
{
	if (data->map[k][j] == 'C' && i == 0)
		ft_drawimg(data, data->coin1, j, k);
	else if (data->map[k][j] == 'C' && i == 1)
		ft_drawimg(data, data->coin2, j, k);
	else if (data->map[k][j] == 'C' && i == 2)
		ft_drawimg(data, data->coin3, j, k);
	else if (data->map[k][j] == 'C' && i == 3)
		ft_drawimg(data, data->coin4, j, k);
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
		ft_drawimg(data, data->exit_closed1, data->e_x, data->e_y);
	else if (i == 1)
		ft_drawimg(data, data->exit_closed2, data->e_x, data->e_y);
	else if (i == 2)
		ft_drawimg(data, data->exit_closed3, data->e_x, data->e_y);
	else if (i == 3)
		ft_drawimg(data, data->exit_closed4, data->e_x, data->e_y);
	i++;
}

void	ft_animexitopen(t_data *data)
{
	static int	i;

	if (i == 2)
		i = 0;
	if (i == 0)
		ft_drawimg(data, data->exit_open1, data->e_x, data->e_y);
	else if (i == 1)
		ft_drawimg(data, data->exit_open2, data->e_x, data->e_y);
	i++;
}

void	ft_animexitclosetoopen(t_data *data)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (i == 0)
		ft_drawimg(data, data->closed_to_open1, data->e_x, data->e_y);
	else if (i == 1)
		ft_drawimg(data, data->closed_to_open2, data->e_x, data->e_y);
	else if (i == 2)
		ft_drawimg(data, data->closed_to_open3, data->e_x, data->e_y);
	else if (i == 3)
	{
		ft_drawimg(data, data->closed_to_open4, data->e_x, data->e_y);
		data->exit_state = 2;
	}
	i++;
}
