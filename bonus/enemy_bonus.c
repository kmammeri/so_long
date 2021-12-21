/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:12:37 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 18:55:51 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_malloc(t_game *game)
{
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
}

void	ft_init_enemy(t_game *game)
{
	int	x;
	int	y;
	int	enemy;

	x = 0;
	y = 0;
	enemy = 0;
	ft_init_malloc(game);
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

void	ft_check_enemy2(t_game *game, int posx, int posy)
{
	int	height[1];
	int	width[1];

	ft_printmap(game);
	printf("\n*****************\n\n  pikachu is KO!");
	printf("\n\n    GAME OVER\n\n*****************\n");
	game->sprite->end = mlx_xpm_file_to_image(game->mlx,
			"sprite/pikachu_ko.xpm", width, height);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->floor, (posx - 1) * 64, (posy - 1) * 64);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->end,
		(posx - 1) * 64, (posy - 1) * 64);
	mlx_string_put(game->mlx, game->window, 150, 21,
		0x00ff0000, "Pikachu is KO!");
	mlx_string_put(game->mlx, game->window, 150, 32,
		0xffffff00, "Press esc to quit");
	mlx_string_put(game->mlx, game->window, 150, 43,
		0xffffff00, "Press r to restart");
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->wasted, (WINDOW_WIDTH / 2) - 287,
		WINDOW_LENGTH / 2 + 20);
	game->endgame = 2;
}

void	ft_check_enemy(t_game *game)
{
	int	i;
	int	posx;
	int	posy;

	posx = ft_position(WINDOW_WIDTH);
	posy = ft_position(WINDOW_LENGTH);
	i = 0;
	while (i < game->enemy->nbenemy)
	{
		if (game->enemy->x[i] == game->player->x
			&& game->enemy->y[i] == game->player->y)
		{
			game->player->movex = 0;
			game->player->movey = 0;
			game->anime = 0;
			game->timer = 0;
			ft_check_enemy2(game, posx, posy);
		}
		i++;
	}
}

void	ft_enemy_move_cdt1(t_game *game, int i)
{
	if (game->player->x > game->enemy->x[i]
		&& game->map[game->enemy->y[i]][game->enemy->x[i] + 1] != '1')
	{
		game->enemy->dir[i] = 3;
		game->enemy->x[i]++;
	}
	else if (game->map[game->enemy->y[i]][game->enemy->x[i] - 1] != '1')
	{
		game->enemy->dir[i] = 2;
		game->enemy->x[i]--;
	}
	else if (game->player->y > game->enemy->y[i]
		&& game->map[game->enemy->y[i] + 1][game->enemy->x[i]] != '1')
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
