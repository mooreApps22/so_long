/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:58 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 15:42:30 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx_linux/mlx.h"
# include "../minilibx_linux/mlx_int.h"
# include <math.h>
# include <errno.h>

# ifndef KEYSYMS
#  define UP_ARROW 0xff52
#  define DOWN_ARROW 0xff54
#  define LEFT_ARROW 0xff51
#  define RIGHT_ARROW 0xff53
#  define W_KEY 0x77
#  define A_KEY 0x61
#  define S_KEY 0x73
#  define D_KEY 0x64
#  define Q_KEY 0x71
#  define ESC_KEY 0xff1b
#  define R_KEY 0x72
#  define G_KEY 0x67
#  define B_KEY 0x62
# endif

# ifndef TEXTURES
#  define LEN 64
#  define X_SWIFTY "texture/swifty.xpm"
#  define X_GROUND "texture/ground.xpm"
#  define X_GEM "texture/gem.xpm"
#  define X_GATE "texture/gate.xpm"
#  define X_HOLE "texture/hole.xpm"
#  define X_WALL "texture/wall.xpm"
# endif

//structures

typedef struct s_vector2
{
	int	y;
	int	x;
}				t_vector2;

enum	e_bool
{
	false,
	true
};

enum	e_dir
{
	NORTH,
	EAST,
	WEST,
	SOUTH
};
enum	e_texture
{
	SWIFTY,
	GROUND,
	GEM,
	GATE,
	HOLE,
	WALL,
	NUM
};

typedef struct s_texture
{
	enum e_texture		id; // = SWIFTY
	char				*xpm;// X_SWIFTY
}		t_texture;

typedef struct s_tile
{
	void	*img; // put to window
}		t_tile;

typedef struct s_map
{
	int		fd;
	char	*line;
	char	**data;
	char	**temp;
	int		rows;
	int		cols;
}		t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_texture	tex[NUM];
	t_tile		tiles[NUM];
	int			key;
	t_vector2	pt1;
	t_vector2	exit;
	int			moves;
	int			swifty;
	int			souls;
	int			total;
	int			exits;
	int			width;
	int			height;
}		t_game;

// main
void	exit_game(t_game *g, char *msg);
void	free_maps(t_game *g);
void	destroy(t_game *g);

// check command line
void	check_command_line(int ac, char **av);

//init game
void	init_map(t_game *g);
void	init_game(t_game *g);

//read map
int		read_map(t_game *g, char **av);

//validate map
void	check_map_dimensions(t_game *g);
void	parse_map_row(t_game *g, char *data, int i);
void	validate_map(t_game *g);

//validate map utils
void	check_swifty(t_game *g, char *data, int y, int x);
void	check_exit(t_game *g, char *data, int y, int x);
void	check_cols_and_is_rect(t_game *g, char *data, int i);
void	check_walls(t_game *g, char *data, int i);
void	check_components(t_game *g, char *data, int i);

//playable map	
void	free_map_temp(t_game *g);
void	check_game_is_playable(t_game *g);

//init xwindow
void	init_xwindow(t_game *g);

//load textures
void	put(t_game *g, void *img, int x, int y);
void	place_tiles(t_game *g);
void	load_tiles(t_game *g);
void	load_textures(t_game *g);

//hooks
int		close_window(t_game *g);
int		input_key(int key, t_game *g);

//moves
void	move_swifty(t_game *g, int dir);

//moves_utils
void	update_souls(t_game *g, int x, int y);

#endif
