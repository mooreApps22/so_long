/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:23:40 by smoore            #+#    #+#             */
/*   Updated: 2024/04/10 19:29:44 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map_temp(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map.rows)
		free(g->map.temp[i++]);
	free(g->map.temp);
	g->map.temp = NULL;
}

static int	flood(t_game *g, char **data, int x, int y)
{
	int	up;
	int	right;
	int	left;
	int	down;

	if (y < 0 || x < 0 || y >= g->map.rows || x >= g->map.cols)
		return (0);
	if (data[y][x] == '1' || data[y][x] == '*')
		return (0);
	if (data[y][x] == 'E')
		return (1);
	if (data[y][x] == 'C')
		g->souls--;
	data[y][x] = '*';
	up = flood(g, data, x, y + 1);
	left = flood(g, data, x - 1, y);
	right = flood(g, data, x + 1, y);
	down = flood(g, data, x, y - 1);
	return (up || left || right || down);
}

void	check_game_is_playable(t_game *g)
{
	int		x;
	int		y;

	x = g->pt1.x;
	y = g->pt1.y;
	if (flood(g, g->map.temp, x, y) && g->souls == 0)
	{
		free_map_temp(g);
		return ;
	}
	else
		exit_game(g, "Game Map not playable.");
}
