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

int ft_exit_anim(t_data *data)
{
    static int  i;
    int num;

    num = 18000;
    i++;
    if (i == num)
	{
		ft_enemy(data);
		ft_anim_coin(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit1, data->e_x * SIZE, data->e_y * SIZE);
	}
    else if (i == num * 2)
	{
		ft_anim_coin(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit2, data->e_x * SIZE, data->e_y * SIZE);
	}
    else if (i == num * 3)
	{
		ft_anim_coin(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit3, data->e_x * SIZE, data->e_y * SIZE);
	}
    else if (i == num * 4)
    {
		ft_anim_coin(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit4, data->e_x * SIZE, data->e_y * SIZE);
        i = 0;
    }
    return (1);
}

void ft_anim_coin(t_data *data)
{
    static int  i;
    static int  j;
    static int  k;

    if (i == 3)
        i = 0;
    k = 0;
    while (k < data->lines)
    {
        j = 0;
        while (data->map[k][j] != '\n' && data->map[k][j] != '\0')
        {
            if (data->map[k][j] == 'C' && i == 0)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit1, j * SIZE, k * SIZE);
            else if (data->map[k][j] == 'C' && i == 1)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit2, j * SIZE, k * SIZE);
            else if (data->map[k][j] == 'C' && i == 2)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit3, j * SIZE, k * SIZE);
            else if (data->map[k][j] == 'C' && i == 3)
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_exit4, j * SIZE, k * SIZE);
            j++;
        }
        k++;
    }
    i++;
}