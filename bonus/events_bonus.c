/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:40:01 by smoore            #+#    #+#             */
/*   Updated: 2024/04/11 18:18:37 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	close_window(t_game *g)
{
	free_maps(g);
	destroy(g);
	ft_printf("You closed the window.");
	exit(1);
}

int	input_key(int key, t_game *g)
{
	if (key == ESC_KEY || key == Q_KEY)
		close_window(g);
	else if (key == UP_ARROW || key == W_KEY)
		move_swifty(g, NORTH);
	else if (key == DOWN_ARROW || key == S_KEY)
		move_swifty(g, SOUTH);
	else if (key == LEFT_ARROW || key == A_KEY)
		move_swifty(g, WEST);
	else if (key == RIGHT_ARROW || key == D_KEY)
		move_swifty(g, EAST);
	ft_printf("Moves: %d\r", g->moves);
	return (0);
}

void	hooks(t_game *g)
{
	mlx_hook(g->win, 17, 1L << 0, close_window, &g);
	mlx_key_hook(g->win, input_key, &g);
	mlx_loop(g->mlx);
}
