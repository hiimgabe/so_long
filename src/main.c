/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:48:56 by gamoreir          #+#    #+#             */
/*   Updated: 2023/05/26 11:45:52 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key)
{
	ft_putchar_fd((char)key, 1);
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	i = -1;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	while (++i < 50)
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
