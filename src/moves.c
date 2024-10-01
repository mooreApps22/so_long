/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:03:51 by smoore            #+#    #+#             */
/*   Updated: 2024/04/16 09:47:05 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	no_collision(t_game *g, int y2, int x2)
{
	char	dest;

	if (x2 < 0 || x2 >= g->map.cols || y2 < 0 || y2 >= g->map.rows)
		return (0);
	dest = g->map.data[y2][x2];
	if (dest == '1' || dest == 'E')
		return (0);
	return (1);
}

void	render_move(t_game *g, int dir, int x, int y)
{
	put(g, g->tiles[GROUND].img, x * LEN, y * LEN);
	if (dir == NORTH)
		y -= 1;
	else if (dir == EAST)
		x += 1;
	else if (dir == WEST)
		x -= 1;
	else if (dir == SOUTH)
		y += 1;
	put(g, g->tiles[SWIFTY].img, x * LEN, y * LEN);
	update_souls(g, x, y);
	g->moves++;
	if (g->map.data[y][x] == 'e' && g->souls == g->total)
	{
		printf("You Won!!!\n");
		close_window(g);
	}
	else
	{
		g->pt1.x = x;
		g->pt1.y = y;
	}
}

void	move_swifty(t_game *g, int dir)
{
	int	x;
	int	y;

	x = g->pt1.x;
	y = g->pt1.y;
	if (dir == NORTH)
		y -= 1;
	else if (dir == EAST)
		x += 1;
	else if (dir == WEST)
		x -= 1;
	else if (dir == SOUTH)
		y += 1;
	if (no_collision(g, y, x))
		render_move(g, dir, g->pt1.x, g->pt1.y);
	if (g->souls == g->total)
		g->map.data[g->exit.y][g->exit.x] = 'e';
	//g->moves++;
}
