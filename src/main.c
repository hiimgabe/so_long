/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:48:56 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/01 11:24:13 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("%s", ARGUMENT_NUMBER_ERROR);
		return (0);
	}
	ft_initfirst(&data);
	if (argc == 2)
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
		{
			ft_printf("%s\n", MLX_PTR_ERROR);
			return (0);
		}
		ft_getspritesfirst(&data, argv[1]);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_input, &data);
		mlx_hook(data.win_ptr, DestroyNotify,
			ButtonPressMask, ft_destroy, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
