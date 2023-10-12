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

# define PLAYER_W1 "./assets/sprites/PLAYER_UP1.xpm"
# define PLAYER_W2 "./assets/sprites/PLAYER_UP2.xpm"
# define PLAYER_A1 "./assets/sprites/PLAYER_LEFT1.xpm"
# define PLAYER_A2 "./assets/sprites/PLAYER_LEFT2.xpm"
# define PLAYER_S1 "./assets/sprites/PLAYER_DOWN1.xpm"
# define PLAYER_S2 "./assets/sprites/PLAYER_DOWN2.xpm"
# define PLAYER_D1 "./assets/sprites/PLAYER_RIGHT1.xpm"
# define PLAYER_D2 "./assets/sprites/PLAYER_RIGHT2.xpm"

# define ENEMY "./assets/sprites/ENEMY.xpm"

# define COIN "./assets/sprites/COIN.xpm"
# define EXIT1 "./assets/sprites/EXIT1.xpm"
# define EXIT2 "./assets/sprites/EXIT2.xpm"
# define EXIT3 "./assets/sprites/EXIT3.xpm"
# define EXIT4 "./assets/sprites/EXIT4.xpm"
# define SIZE 64

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
	void	*img_exit1;
	void	*img_exit2;
	void	*img_exit3;
	void	*img_exit4;
	void	*img_w1;
	void	*img_w2;
	void	*img_a1;
	void	*img_a2;
	void	*img_s1;
	void	*img_s2;
	void	*img_d1;
	void	*img_d2;
	int	p_x;
	int	p_y;
	int	x;
	int	y;
	int	moves;
	int	score;
	int	fd;
	int	e_x;
	int	e_y;
	int	columns;
	int	lines;
	int	player;
	int	exit;
	int	coin;
	int	enemy;
	char	**map;
}	t_data;

void	ft_init(t_data *data);
int	ft_cntlines(t_data *data);
int	ft_len(char const *str);

// MAP
void	ft_getsprites(t_data *data, char *mapname);
void	ft_initmap(t_data *data, char *mapname);
void	ft_fill_window(t_data *data, int i, int j);
void	ft_fill_map(t_data *data);

int	ft_exit_anim(t_data *d);
void ft_anim_coin(t_data *data);

void	ft_enemy(t_data *data);
void	ft_movecheck(t_data *data, int	random, int	y, int x);
int	ft_moveenemy(t_data *data, int	y, int x, char key);
void	ft_enemysprite(t_data *data, int y, int x, char key);

// PLAYER
int	handle_input(int keysym, t_data *data);
int	ft_moveplayer(t_data *data, int y, int x, char key);
void	ft_playercoordinates(t_data *data);
void	ft_drawimg(t_data *data, int y, int x, char key);

//CLEAR
void	ft_clear_map(t_data *data);
int		ft_clear(t_data	*data);

#endif
