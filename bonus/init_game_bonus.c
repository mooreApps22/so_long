/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:46:26 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 13:15:56 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_map(t_game *g)
{
	g->map.fd = 0;
	g->map.line = NULL;
	g->map.data = NULL;
	g->map.temp = NULL;
	g->map.rows = 0;
	g->map.cols = 0;
}

void	init_game(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->pt1.x = 0;
	g->pt1.y = 0;
	g->exit.x = 0;
	g->exit.y = 0;
	g->moves = 0;
	g->swifty = 0;
	g->souls = 0;
	g->total = 0;
	g->exits = 0;
	g->width = 0;
	g->height = 0;
	init_map(g);
	ft_printf("... %d ...\n", g->pt1.x);
}
