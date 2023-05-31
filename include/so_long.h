/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:46:38 by gamoreir          #+#    #+#             */
/*   Updated: 2023/05/31 15:58:10 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <fcntl.h>

# define SIZE 45

# define WALL "../assets/sprites.WALL.xpm"

# define MLX_PTR_ERROR "ERROR : mlx_ptr failed."
# define MLX_WIN_PTR_ERROR "ERROR : win_ptr failed."


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	int	x;
	int	y;
	int	fd;
	int	columns;
	int	rows;
	char	**map;
}	t_data;

void	ft_initdata(t_data *data);
int	ft_cntrows(t_data *data);
int	ft_len(char const *str);

// MAP
void	ft_getsprites(t_data *data, char *mapname);
void	ft_initmap(t_data *data, char *mapname);
void	ft_fill_window(t_data *data, int i, int j);
void	ft_fill_map(t_data *data);

#endif
