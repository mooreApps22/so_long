/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:26:36 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 13:31:20 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	update_souls(t_game *g, int x, int y)
{
	if (g->map.data[y][x] == 'C')
	{
		g->souls++;
		g->map.data[y][x] = '0';
		g->pt1.x = x;
		g->pt1.y = y;
		if (g->souls == g->total)
			put(g, g->tile[HOLE].img, g->exit.x * LEN, g->exit.y * LEN);
	}
}
