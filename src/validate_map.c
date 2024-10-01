/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:01:48 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 15:22:39 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_dimensions(t_game *g)
{
	int	row;
	int	col;

	row = g->map.rows;
	col = g->map.cols;
	if (row < 3 && col < 5)
		exit_game(g, "Map too small.");
	else if (row < 4 && col < 4)
		exit_game(g, "Map too small.");
	else if (row < 5 && col < 3)
		exit_game(g, "Map too small.");
}

void	parse_map_row(t_game *g, char *data, int i)
{
	if (!g)
		return ;
	check_cols_and_is_rect(g, data, i);
	check_walls(g, data, i);
	check_components(g, data, i);
	check_map_dimensions(g);
}

void	validate_map(t_game *g)
{
	int	i;

	if (!g)
		return ;
	i = 0;
	ft_printf("\tRow: %d\n", g->map.rows);
	while (i < g->map.rows)
	{
		parse_map_row(g, g->map.data[i], i);
		i++;
	}
	if (g->exits != 1 || g->souls == 0 || g->swifty != 1)
		exit_game(g, "Check Map Components.");
	check_game_is_playable(g);
	ft_printf("Pt1: (%d, %d)\n", g->pt1.x, g->pt1.y);
}
