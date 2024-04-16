/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:36 by smoore            #+#    #+#             */
/*   Updated: 2024/04/12 15:18:30 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map_data(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map.rows)
		free(g->map.data[i++]);
	free(g->map.data);
	g->map.data = NULL;
}

void	free_maps(t_game *g)
{
	if (g)
	{
		if (g->map.data)
			free_map_data(g);
		if (g->map.temp)
			free_map_temp(g);
	}
}

void	destroy(t_game *g)
{
	int	i;

	i = 0;
	while (i < NUM)
		mlx_destroy_image(g->mlx, g->tiles[i++].img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}

void	exit_game(t_game *g, char *msg)
{
	free_maps(g);
	if (g->mlx)
		destroy(g);
	perror(":Error\n ");
	ft_printf("%s", msg);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	g;

	ft_printf("====MANDATORY SO LONG====\n");
	check_command_line(ac, av);
	init_game(&g);
	read_map(&g, av);
	validate_map(&g);
	init_xwindow(&g);
	mlx_hook(g.win, 17, 1L << 0, close_window, &g);
	mlx_key_hook(g.win, input_key, &g);
	mlx_loop(g.mlx);
	exit_game(&g, "End of game.");
	return (EXIT_SUCCESS);
}
