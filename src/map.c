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
				ft_drawimg(data, data->coin4, j, i);
			else if (data->map[i][j] == 'M')
				ft_drawimg(data, data->enemy1, j, i);
			else if (data->map[i][j] == 'E')
				ft_drawimg(data, data->exit_closed3, j, i);
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
			ft_len(data->map[0]) * SIZE, data->lines * SIZE, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		ft_printf("%s\n", MLX_WIN_PTR_ERROR);
		return ;
	}
	ft_fill_window(data, i, j);
	close(data->fd);
}
