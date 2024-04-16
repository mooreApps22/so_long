/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:56:21 by smoore            #+#    #+#             */
/*   Updated: 2024/04/11 18:18:19 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_command_line(int ac, char **av)
{
	int	len;

	errno = 22;
	if (ac < 2)
	{
		errno = 2;
		perror("Error:\n Correct Usage <./so_long> <map/mapX.ber>");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		perror("Error:\n Can only be one arguments.");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(av[1]);
	if (!ft_strnstr(av[1], ".ber", len))
	{
		perror("Error:\n Must be .ber file extension.");
		exit(EXIT_FAILURE);
	}
	ft_printf("Map Filename: <%s>\n", av[1]);
}
