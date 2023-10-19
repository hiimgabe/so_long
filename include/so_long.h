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

# define WALL1 "./assets/sprites/WALL1.xpm"
# define WALL2 "./assets/sprites/WALL2.xpm"
# define WALL3 "./assets/sprites/WALL3.xpm"
# define WALL4 "./assets/sprites/WALL4.xpm"
# define WALL5 "./assets/sprites/WALL5.xpm"
# define WALL6 "./assets/sprites/WALL6.xpm"

# define FLOOR "./assets/sprites/FLOOR.xpm"

# define PLAYER_W1 "./assets/sprites/PLAYER_UP1.xpm"
# define PLAYER_W2 "./assets/sprites/PLAYER_UP2.xpm"
# define PLAYER_A1 "./assets/sprites/PLAYER_LEFT1.xpm"
# define PLAYER_A2 "./assets/sprites/PLAYER_LEFT2.xpm"
# define PLAYER_S1 "./assets/sprites/PLAYER_DOWN1.xpm"
# define PLAYER_S2 "./assets/sprites/PLAYER_DOWN2.xpm"
# define PLAYER_D1 "./assets/sprites/PLAYER_RIGHT1.xpm"
# define PLAYER_D2 "./assets/sprites/PLAYER_RIGHT2.xpm"

# define ENEMY1 "./assets/sprites/ENEMY1.xpm"
# define ENEMY2 "./assets/sprites/ENEMY2.xpm"

# define COIN1 "./assets/sprites/COIN1.xpm"
# define COIN2 "./assets/sprites/COIN2.xpm"
# define COIN3 "./assets/sprites/COIN3.xpm"
# define COIN4 "./assets/sprites/COIN4.xpm"

# define EXIT_CLOSED1 "./assets/sprites/EXIT_CLOSED1.xpm"
# define EXIT_CLOSED2 "./assets/sprites/EXIT_CLOSED2.xpm"
# define EXIT_CLOSED3 "./assets/sprites/EXIT_CLOSED3.xpm"
# define EXIT_CLOSED4 "./assets/sprites/EXIT_CLOSED4.xpm"

# define CLOSED_TO_OPEN1 "./assets/sprites/CLOSED_TO_OPEN1.xpm"
# define CLOSED_TO_OPEN2 "./assets/sprites/CLOSED_TO_OPEN2.xpm"
# define CLOSED_TO_OPEN3 "./assets/sprites/CLOSED_TO_OPEN3.xpm"
# define CLOSED_TO_OPEN4 "./assets/sprites/CLOSED_TO_OPEN4.xpm"

# define EXIT_OPEN1 "./assets/sprites/EXIT_OPEN1.xpm"
# define EXIT_OPEN2 "./assets/sprites/EXIT_OPEN2.xpm"

# define SIZE 64

# define MLX_PTR_ERROR "ERROR : mlx_ptr failed."
# define MLX_WIN_PTR_ERROR "ERROR : win_ptr failed."

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall1;
	void	*img_wall2;
	void	*img_wall3;
	void	*img_wall4;
	void	*img_wall5;
	void	*img_wall6;
	void	*img_floor;
	void	*img_coin1;
	void	*img_coin2;
	void	*img_coin3;
	void	*img_coin4;
	void	*img_enemy1;
	void	*img_enemy2;
	void	*img_exit_closed1;
	void	*img_exit_closed2;
	void	*img_exit_closed3;
	void	*img_exit_closed4;
	void	*img_closed_to_open1;
	void	*img_closed_to_open2;
	void	*img_closed_to_open3;
	void	*img_closed_to_open4;
	void	*img_exit_open1;
	void	*img_exit_open2;
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
	int	exit_state;
	int	coin;
	int	enemy;
	char	**map;
	char	**map_check;
}	t_data;

void	ft_init(t_data *data);
int	ft_cntlines(t_data *data);
int	ft_len(char const *str);

// MAP
void	ft_getsprites(t_data *data, char *mapname);
void	ft_initmap(t_data *data, char *mapname);
void	ft_fill_window(t_data *data, int i, int j);
void	ft_fill_map(t_data *data);
void	ft_dupmap(t_data *data);
void	ft_drawwall(t_data *data, int y, int x);

int	ft_animations(t_data *d);
void    ft_animexitclosed(t_data *data);
void    ft_animexitopen(t_data *data);
void ft_animcoin(t_data *data);
void	ft_animexitclosetoopen(t_data *data);
void	ft_enemyanim(t_data *data);

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
void	ft_clear_map2(t_data *data);
int		ft_clear(t_data	*data);

void	ft_checkcolumns(t_data *data);
void	ft_checklines(t_data *data);
void	ft_checkrectangle(t_data *data);
void	ft_checkchars(t_data *data);
void	ft_checkwalls(t_data *data);
void	ft_getexitcoords(t_data *data, int i, int j);
void	ft_checkgamecomponents(t_data *data);
void	ft_checkpath(t_data *data);
int	ft_floodfill(t_data *data, char **map, int x, int y);


#endif
