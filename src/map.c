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
	while (i <= data->lines)
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
	ft_checklines(data);
	ft_checkrectangle(data);
}

void	ft_drawwall(t_data *data, int i, int j)
{
	int	random;

	random = rand () % 2;
	if (j == 0 || j == data->columns - 1)
		ft_drawimg(data, data->wall4, j, i);
	else if (i == 0 && j == data->columns / 2)
		ft_drawimg(data, data->wall3, j, i);
	else if (i == 0 && j > 0 && j < data->columns - 1 && random == 0)
		ft_drawimg(data, data->wall1, j, i);
	else if (i == 0 && j > 0 && j < data->columns - 1 && random == 1)
		ft_drawimg(data, data->wall2, j, i);
	else if (i == data->lines - 1 && j > 0
		&& j < data->columns - 1 && random == 0)
		ft_drawimg(data, data->wall4, j, i);
	else if (i == data->lines - 1 && j > 0
		&& j < data->columns - 1 && random == 1)
		ft_drawimg(data, data->wall5, j, i);
	else if (i > 0 && i < data->lines - 1 && j > 0 && j < data->columns - 1)
		ft_drawimg(data, data->wall6, j, i);
}

void	ft_fill_window(t_data *data, int i, int j)
{
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				ft_drawwall(data, i, j);
			else if (data->map[i][j] == 'P')
				ft_drawimg(data, data->d1, j, i);
			else if (data->map[i][j] == '0')
				ft_drawimg(data, data->floor, j, i);
			else if (data->map[i][j] == 'C')
				ft_drawimg(data, data->coin1, j, i);
			else if (data->map[i][j] == 'M')
				ft_drawimg(data, data->enemy1, j, i);
			else if (data->map[i][j] == 'E')
				ft_drawimg(data, data->exit_closed1, j, i);
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
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			ft_len(data->map[0]) * SIZE, data->lines * SIZE + 25, "so_long");
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
	ft_initmap(data, mapname);
}
