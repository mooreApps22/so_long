/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xwindow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:00:20 by smoore            #+#    #+#             */
/*   Updated: 2024/04/09 15:11:44 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_xwindow(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		exit_game(g, "MLX failed to connect.");
	else if (g->mlx)
		ft_printf("MLX is up ...\n");
	g->width = (g->map.cols * LEN);
	g->height = (g->map.rows * LEN);
	g->win = mlx_new_window(g->mlx, g->width, g->height, "So Long");
	if (!g->win)
		exit_game(g, "Window failed.");
	load_textures(g);
}
