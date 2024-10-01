/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:40:06 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 14:53:55 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_cols_and_is_rect(t_game *g, char *data, int i)
{
	if (!data)
		return ;
	if (i == 0)
	{
		g->map.cols = ft_strlen(data);
		if (g->map.cols < 3)
			exit_game(g, "Map has too few columns.");
		else if ((int)ft_strlen(data) != g->map.cols)
			exit_game(g, "Map is not a rectangle");
	}
}

void	check_walls(t_game *g, char *data, int i)
{
	if (i == 0 || i == g->map.rows - 1)
	{
		while (*data)
		{
			if (*data != '1')
				exit_game(g, "Map: North or south wall broken.");
			data++;
		}
	}
	else if (data[0] != '1' || data[g->map.cols - 1] != '1')
		exit_game(g, "Map: East or west wall broken.");
}

void	check_swifty(t_game *g, char *data, int y, int x)
{
	if (!data)
		return ;
	g->swifty++;
	g->pt1.y = y;
	g->pt1.x = x;
	ft_printf("SWY-Start: (%d, %d)\n", g->pt1.x, g->pt1.y);
}

void	check_exit(t_game *g, char *data, int y, int x)
{
	if (!data)
		return ;
	g->exits++;
	g->exit.y = y;
	g->exit.x = x;
}

void	check_components(t_game *g, char *data, int y)
{
	int	x;

	x = 0;
	while (*data)
	{
		if (*data == 'C')
		{
			g->souls++;
			g->total++;
		}
		else if (*data == 'E')
			check_exit(g, data, y, x);
		else if (*data == 'P')
			check_swifty(g, data, y, x);
		data++;
		x++;
	}
	ft_printf("\tEx: %d, Gems: %d, Sw: %d\n", g->exits, g->souls, g->swifty);
}
