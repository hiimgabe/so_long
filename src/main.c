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
		ft_printf("Wrong number of arguments.\nTry again ex: ./so_long assets/maps/map1.ber");
		return (0);
	}
	ft_init(&data);
	if (argc == 2)
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
		{
			ft_printf("%s\n", MLX_PTR_ERROR);
			return (0);
		}
		ft_getsprites(&data, argv[1]);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_input, &data);
		mlx_hook(data.win_ptr, DestroyNotify, ButtonPressMask, ft_clear, &data);
		mlx_loop_hook(data.mlx_ptr, ft_exitclosedanim, &data);
		//mlx_loop_hook(data.mlx_ptr, ft_anim_coin, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
/*
	data.mlx_ptr = mlx_init();
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, 32, 32);
	if (data.mlx_ptr == NULL)
		return (ft_printf("%s", MLX_PTR_ERROR));
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (ft_printf("%s", MLX_WIN_PTR_ERROR));
	}
	mlx_key_hook(data.win_ptr, KeyPressMask, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
*/
