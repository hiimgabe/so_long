/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:48:06 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:21:58 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
