/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:01:48 by smoore            #+#    #+#             */
/*   Updated: 2024/04/11 18:20:54 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	parse_map_row(t_game *g, char *data, int i)
{
	if (!g)
		return ;
	check_cols_and_is_rect(g, data, i);
	check_walls(g, data, i);
	check_components(g, data, i);
}

void	validate_map(t_game *g)
{
	int	i;

	if (!g)
		return ;
	i = 0;
	ft_printf("... Row: %d ...\n", g->map.rows);
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
