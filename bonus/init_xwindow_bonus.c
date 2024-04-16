/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xwindow_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:00:20 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 19:32:08 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_xwindow(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		exit_game(g, "MLX failed to connect.");
	else if (g->mlx)
		ft_printf("... MLX is up ...\n");
	g->width = (g->map.cols * LEN);
	g->height = (g->map.rows * LEN);
	g->win = mlx_new_window(g->mlx, g->width, g->height, "So Long");
	if (!g->win)
		exit_game(g, "Window failed.");
	else if (g->win)
		ft_printf("... Window is up ...\n");
	load_textures(g);
}
