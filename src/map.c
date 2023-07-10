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

void	ft_fill_map(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < data->lines)
	{
		str = get_next_line(data->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		data->map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	data->columns = ft_strlen(data->map[0]);
	ft_playercoordinates(data);
}

void ft_fill_window(t_data *data, int i, int j)
{
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_wall, j * SIZE, i * SIZE);
			}
			else if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, j * SIZE, i * SIZE);
			}
			else if (data->map[i][j] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_floor, j * SIZE, i * SIZE);
			}
			else if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_coin, j * SIZE, i * SIZE);
			}
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_enemy, j * SIZE, i * SIZE);
			}
			j++;
		}
		i++;
	}
}

void	ft_initmap(t_data *data, char *mapname)
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	data->fd = open(mapname, O_RDONLY);
	data->lines = ft_cntlines(data);
	close(data->fd);
	data->fd = open(mapname, O_RDONLY);
	data->map = ft_calloc(data->lines + 1, sizeof(char *));
	ft_fill_map(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_len(data->map[0]) * SIZE, data->lines * SIZE, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		ft_printf("%s\n", MLX_WIN_PTR_ERROR);
		return ;
	}
	ft_fill_window(data, i, j);
	close(data->fd);
}

void	ft_getsprites(t_data *data, char *mapname)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &data->x, &data->y);
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &data->x, &data->y);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &data->x, &data->y);
	data->img_coin = mlx_xpm_file_to_image(data->mlx_ptr, COIN, &data->x, &data->y);
	data->img_enemy = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY, &data->x, &data->y);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &data->x, &data->y);
	ft_initmap(data, mapname);
}
