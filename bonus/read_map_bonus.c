/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:32:58 by smoore            #+#    #+#             */
/*   Updated: 2024/04/11 18:20:29 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	count_rows(t_game *g, char **av)
{
	char	*line;

	line = NULL;
	g->map.fd = open(av[1], O_RDONLY);
	if (!g->map.fd || g->map.fd == -1)
		exit_game(g, "Map failed to open.");
	while (1)
	{
		line = get_next_line(g->map.fd);
		if (!line || g->map.fd == 0)
			break ;
		g->map.rows++;
		free(line);
	}
	close(g->map.fd);
	if (g->map.rows < 3)
		exit_game(g, "Map rows too few.");
}

int	read_map(t_game *g, char **av)
{
	int	i;

	i = 0;
	count_rows(g, av);
	if (g->map.rows)
	{
		g->map.data = (char **)malloc(sizeof(char *) * g->map.rows);
		g->map.temp = (char **)malloc(sizeof(char *) * g->map.rows);
		g->map.fd = open(av[1], O_RDONLY);
		ft_printf("==== MAP ====\n");
		while (i < g->map.rows)
		{
			g->map.line = get_next_line(g->map.fd);
			g->map.data[i] = ft_strtrim(g->map.line, "\n");
			g->map.temp[i] = ft_strdup(g->map.data[i]);
			free(g->map.line);
			ft_printf("Data[] = %s\n", g->map.data[i]);
			i++;
		}
		close(g->map.fd);
		return (g->map.rows);
	}
	return (0);
}
