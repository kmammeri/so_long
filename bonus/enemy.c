/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:12:37 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/20 21:41:23 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_enemy(t_game *game)
{
	int	x;
	int	y;
	int	enemy;

	x = 0;
	y = 0;
	enemy = 0;
	if (game->enemy->nbenemy == 0)
		return ;
	game->enemy->x = malloc(sizeof(int) * game->enemy->nbenemy);
	if (!game->enemy->x)
		ft_close(game);
	game->enemy->y = malloc(sizeof(int) * game->enemy->nbenemy);
	if (!game->enemy->y)
		ft_close(game);
	game->enemy->dir = malloc(sizeof(int) * game->enemy->nbenemy);
	if (!game->enemy->dir)
		ft_close(game);
	while (y < game->lenth && enemy < game->enemy->nbenemy)
	{
		while (x < game->width && enemy < game->enemy->nbenemy)
		{
			if (game->map[y][x] == 'P' && x < game->width && y < game->lenth)
			{
				game->enemy->x[enemy] = x;
				game->enemy->y[enemy] = y;
				game->enemy->dir[enemy] = 0;
				enemy++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_check_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy->nbenemy)
	{
		if (game->enemy->x[i] == game->player->x && game->enemy->y[i] == game->player->y)
		{
			printf("\n*****************\n\n  Pikachu is KO!");
			printf("\n\n    GAME OVER\n\n*****************\n");
			ft_close(game);
		}
		i++;
	}
}

void	ft_enemy_move(t_game *game)
{
	int	i;
	int	gap_x;
	int	gap_y;

	i = 0;
	while (i < game->enemy->nbenemy)
	{
		if (game->player->x > game->enemy->x[i])
			gap_x = game->player->x - game->enemy->x[i];
		else
			gap_x = game->enemy->x[i] - game->player->x;
		if (game->player->y > game->enemy->y[i])
			gap_y = game->player->y - game->enemy->y[i];
		else
			gap_y = game->enemy->y[i] - game->player->y;
		if (gap_x > gap_y)
		{
			if (game->player->x > game->enemy->x[i] && game->map[game->enemy->y[i]][game->enemy->x[i] + 1] != '1')
			{
				game->enemy->dir[i] = 3;
				game->enemy->x[i]++;
			}
			else if (game->map[game->enemy->y[i]][game->enemy->x[i] - 1] != '1')
			{
				game->enemy->dir[i] = 2;
				game->enemy->x[i]--;
			}
			else if (game->player->y > game->enemy->y[i] && game->map[game->enemy->y[i] + 1][game->enemy->x[i]] != '1')
			{
				game->enemy->dir[i] = 0;
				game->enemy->y[i]++;
			}
			else if (game->map[game->enemy->y[i] - 1][game->enemy->x[i]] != '1')
			{
				game->enemy->dir[i] = 1;
				game->enemy->y[i]--;
			}
		}
		else
		{
			if (game->player->y > game->enemy->y[i] && game->map[game->enemy->y[i] + 1][game->enemy->x[i]] != '1')
			{
				game->enemy->dir[i] = 0;
				game->enemy->y[i]++;
			}
			else if (game->map[game->enemy->y[i] - 1][game->enemy->x[i]] != '1')
			{
				game->enemy->dir[i] = 1;
				game->enemy->y[i]--;
			}
			else if (game->map[game->enemy->y[i]][game->enemy->x[i] - 1] != '1')
			{
				game->enemy->dir[i] = 2;
				game->enemy->x[i]--;
			}
			else if (game->player->x > game->enemy->x[i] && game->map[game->enemy->y[i]][game->enemy->x[i] + 1] != '1')
			{
				game->enemy->dir[i] = 3;
				game->enemy->x[i]++;
			}
		}
		i++;
	}
}

void	ft_print_enemy(t_game *game, int x, int y)
{
	int	i;
	int	posx;
	int	posy;

	posx = ft_position(WINDOW_WIDTH);
	posy = ft_position(WINDOW_LENTH);
	i = 0;
	while (i < game->enemy->nbenemy)
	{
		if (game->player->x + 1 + x - posx == game->enemy->x[i] && game->player->y + 1 + y - posy == game->enemy->y[i])
		{
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->enemy[game->enemy->dir[i]], 64 * x + game->player->movex * 32, 64 * y + game->player->movey * 32);
		}
		i++;
	}
}
