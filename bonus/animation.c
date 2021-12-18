/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:46 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/18 20:17:42 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_delay(t_game *game)
{
	if (game->anime == 1)
	{
		ft_printmap(game);
		printf("coucou\n");
		if (game->timer < 20)
			game->timer++;
		else
		{
			ft_sprite(game);
			ft_printmap(game);
			game->player->movex = 0;
			game->player->movey = 0;
			game->anime = 0;
			game->timer = 0;
			ft_printmap(game);
		}
	}
	printf("salut\n");
	return (0);
}
