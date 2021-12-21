/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:04:27 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 20:15:29 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_up(t_game *game)
{
	if (game->map[game->player->y - 1][game->player->x]
	!= '1' && game->anime == 0)
	{
		if (game->anime == 0)
			game->player->dir = 1;
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->y--;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		ft_sprite_vertical_move(game);
		game->anime = 1;
		game->player->movey = -1;
	}
	ft_end(game);
	ft_printmap(game);
}

void	ft_down(t_game *game)
{
	if (game->map[game->player->y + 1][game->player->x]
	!= '1' && game->anime == 0)
	{	
		if (game->anime == 0)
			game->player->dir = 0;
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->y++;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		ft_sprite_vertical_move(game);
		game->anime = 1;
		game->player->movey = 1;
	}
	ft_end(game);
	ft_printmap(game);
}

void	ft_left(t_game *game)
{
	if (game->map[game->player->y][game->player->x - 1]
	!= '1' && game->anime == 0)
	{
		if (game->anime == 0)
			game->player->dir = 3;
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->x--;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		ft_sprite_horizontal_move(game);
		game->anime = 1;
		game->player->movex = -1;
	}
	ft_end(game);
	ft_printmap(game);
}

void	ft_right(t_game *game)
{
	if (game->map[game->player->y][game->player->x + 1]
	!= '1' && game->anime == 0)
	{
		if (game->anime == 0)
			game->player->dir = 2;
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->x++;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		ft_sprite_horizontal_move(game);
		game->anime = 1;
		game->player->movex = 1;
	}
	ft_end(game);
	ft_printmap(game);
}

void	ft_restart(t_game *game)
{
	int	i;

	i = 0;
	game->endgame = 0;
	if (game->player)
		free(game->player);
	if (game->sprite)
		free(game->sprite);
	while (game->map && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	if (game->enemy && game->enemy->x)
	{
		free(game->enemy->x);
		free(game->enemy->y);
		free(game->enemy->dir);
		free(game->enemy);
	}
	game = ft_mapping(game->arg, game);
}
