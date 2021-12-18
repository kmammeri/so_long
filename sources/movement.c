/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:04:27 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/17 14:45:33 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_up(t_game *game)
{
	if (game->map[game->player->y - 1][game->player->x] != '1')
	{
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->y--;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		if (game->map[game->player->y][game->player->x] == 'E'
		&& game->nbcollectible == 0)
		{
			game->map[game->player->y][game->player->x] = '0';
			game->endgame = 1;
			printf("\n*****************\n*****************\n\n    SUCCESS\n\n");
			printf("   score = %d\n", game->player->move);
			printf("\nPRESS ESC TO EXIT\n");
			printf("\n*****************\n*****************\n\n");
		}
	}
	game->player->dir = 1;
	ft_printmap(game);
}

void	ft_down(t_game *game)
{
	if (game->map[game->player->y + 1][game->player->x] != '1')
	{	
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->y++;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		if (game->map[game->player->y][game->player->x] == 'E'
		&& game->nbcollectible == 0)
		{
			game->map[game->player->y][game->player->x] = '0';
			game->endgame = 1;
			printf("\n*****************\n*****************\n\n    SUCCESS\n\n");
			printf("   score = %d\n", game->player->move);
			printf("\nPRESS ESC TO EXIT\n");
			printf("\n*****************\n*****************\n\n");
		}
	}
	game->player->dir = 0;
	ft_printmap(game);
}

void	ft_left(t_game *game)
{
	if (game->map[game->player->y][game->player->x - 1] != '1')
	{
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->x--;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		if (game->map[game->player->y][game->player->x] == 'E'
		&& game->nbcollectible == 0)
		{
			game->map[game->player->y][game->player->x] = '0';
			game->endgame = 1;
			printf("\n*****************\n*****************\n\n    SUCCESS\n\n");
			printf("   score = %d\n", game->player->move);
			printf("\nPRESS ESC TO EXIT\n");
			printf("\n*****************\n*****************\n\n");
		}
	}
	game->player->dir = 3;
	ft_printmap(game);
}

void	ft_right(t_game *game)
{
	if (game->map[game->player->y][game->player->x + 1] != '1')
	{
		game->player->move++;
		printf("move = %d\n", game->player->move);
		game->player->x++;
		if (game->map[game->player->y][game->player->x] == 'C')
		{
			game->map[game->player->y][game->player->x] = '0';
			game->nbcollectible--;
		}
		if (game->map[game->player->y][game->player->x] == 'E'
		&& game->nbcollectible == 0)
		{
			game->map[game->player->y][game->player->x] = '0';
			game->endgame = 1;
			printf("\n*****************\n*****************\n\n    SUCCESS\n\n");
			printf("   score = %d\n", game->player->move);
			printf("\nPRESS ESC TO EXIT\n");
			printf("\n*****************\n*****************\n\n");
		}
	}
	game->player->dir = 2;
	ft_printmap(game);
}

int	ft_press_key(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		if (game->endgame == 0)
			printf("\n*****************\n\n   YOU FAILED\n\n*****************\n");
		ft_close(game);
	}
	else if (keycode == 13 && game->endgame == 0)
	{
		ft_up(game);
	}
	else if (keycode == 1 && game->endgame == 0)
	{
		ft_down(game);
	}
	else if (keycode == 2 && game->endgame == 0)
	{
		ft_right(game);
	}
	else if (keycode == 0 && game->endgame == 0)
	{
		ft_left(game);
	}
	return (0);
}
