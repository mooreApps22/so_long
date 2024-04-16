/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:17:43 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 11:35:50 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x, y);
}

void	place_tiles(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.cols)
		{
			if (g->map.data[y][x] == '1')
				put(g, g->tiles[WALL].img, x * LEN, y * LEN);
			else if (g->map.data[y][x] == 'E')
				put(g, g->tiles[GATE].img, x * LEN, y * LEN);
			else if (g->map.data[y][x] == 'e')
				put(g, g->tiles[HOLE].img, x * LEN, y * LEN);
			else if (g->map.data[y][x] == 'C')
				put(g, g->tiles[GEM].img, x * LEN, y * LEN);
			else if (g->map.data[y][x] == 'P')
				put(g, g->tiles[SWIFTY].img, x * LEN, y * LEN);
			else if (g->map.data[y][x] == '0')
				put(g, g->tiles[GROUND].img, x * LEN, y * LEN);
			x++;
		}
		y++;
	}
}

void	load_tiles(t_game *g)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < NUM)
	{
		g->tiles[i].img = mlx_xpm_file_to_image(g->mlx, g->tex[i].xpm, &w, &h);
		i++;
	}
}

void	load_textures(t_game *g)
{
	g->tex[SWIFTY].id = SWIFTY;
	g->tex[SWIFTY].xpm = X_SWIFTY;
	g->tex[GROUND].id = GROUND;
	g->tex[GROUND].xpm = X_GROUND;
	g->tex[GEM].id = GEM;
	g->tex[GEM].xpm = X_GEM;
	g->tex[GATE].id = GATE;
	g->tex[GATE].xpm = X_GATE;
	g->tex[HOLE].id = HOLE;
	g->tex[HOLE].xpm = X_HOLE;
	g->tex[WALL].id = WALL;
	g->tex[WALL].xpm = X_WALL;
	load_tiles(g);
	place_tiles(g);
}
