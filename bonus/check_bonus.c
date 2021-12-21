/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:56:08 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 18:42:31 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_checkwall(t_game *game, int i, int j)
{
	if (game->map[0][j] != '1' || game->map[game->lenth - 1][j] != '1')
	{
		write(1, "Error!\nOpen horizontal wall\n", 28);
		ft_close(game);
	}
	else if (game->map[i][0] != '1' || (game->map[i][game->width - 1] != '1'))
	{
		write(1, "Error!\nOpen vertical wall\n", 26);
		ft_close(game);
	}
}

void	ft_checkchar(t_game *game)
{
	if (game->nbmc == 0)
	{
		write(1, "Error!\nThere is no player on the map\n", 37);
		ft_close(game);
	}
	else if (game->nbexit == 0)
	{
		write(1, "Error!\nThere is no exit on the map\n", 35);
		ft_close(game);
	}
	else if (game->nbcollectible == 0)
	{
		write(1, "Error!\nThere is no collectible on the map\n", 42);
		ft_close(game);
	}
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)chr)
			return ((char *)str + i);
		i++;
	}
	if (str && (str[i] == (char)chr))
		return ((char *)str + i);
	return (NULL);
}
