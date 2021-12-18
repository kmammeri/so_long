/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:56:08 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/17 14:52:05 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_checkwall(t_game *game, int i, int j)
{
	if (game->map[0][j] != '1' || game->map[game->lenth - 1][j] != '1')
	{
		write(1, "Error!\nOpen horizontal wall\n", 28);
		exit(0);
	}
	else if (game->map[i][0] != '1' || (game->map[i][game->width - 1] != '1'))
	{
		write(1, "Error!\nOpen vertical wall\n", 26);
		exit(0);
	}
}

void	ft_checkchar(t_game *game)
{
	if (game->nbmc == 0)
	{
		write(1, "Error!\nThere is no player on the map\n", 37);
		exit(0);
	}
	else if (game->nbexit == 0)
	{
		write(1, "Error!\nThere is no exit on the map\n", 35);
		exit(0);
	}
	else if (game->nbcollectible == 0)
	{
		write(1, "Error!\nThere is no collectible on the map\n", 42);
		exit(0);
	}
}
