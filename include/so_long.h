/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:46:38 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/02 16:23:38 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <fcntl.h>

# define WALL "./assets/sprites/WALL.xpm"
# define FLOOR "./assets/sprites/FLOOR.xpm"
# define PLAYER "./assets/sprites/PLAYER.xpm"
# define ENEMY "./assets/sprites/ENEMY.xpm"
# define COIN "./assets/sprites/COIN.xpm"
# define EXIT "./assets/sprites/EXIT.xpm"
# define SIZE 32

# define MLX_PTR_ERROR "ERROR : mlx_ptr failed."
# define MLX_WIN_PTR_ERROR "ERROR : win_ptr failed."


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_enemy;
	void	*img_player;
	void	*img_exit;
	int	moves;
	int	x;
	int	y;
	int	p_x;
	int	p_y;
	int	fd;
	int	columns;
	int	lines;
	int	p;
	int	c;
	int	e;
	char	**map;
}	t_data;

void	ft_initdata(t_data *data);
int	ft_cntlines(t_data *data);
int	ft_len(char const *str);

// MAP
void	ft_getsprites(t_data *data, char *mapname);
void	ft_initmap(t_data *data, char *mapname);
void	ft_fill_window(t_data *data, int i, int j);
void	ft_fill_map(t_data *data);

// PLAYER
int	handle_input(int keysym, t_data *data);
int	ft_moveplayer(t_data *data, int y, int x, char key);
void	ft_playercoordinates(t_data *data);

//CLEAR
void	ft_clear_map(t_data *data);
int		ft_clear(t_data	*data);

#endif
