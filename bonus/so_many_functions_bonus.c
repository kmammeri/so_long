/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_many_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:49:02 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 20:17:01 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_press_key(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		if (game->endgame == 0)
			printf("\n*****************\n\n   YOU FAILED\n\n*****************\n");
		ft_close(game);
	}
	else if (keycode == 15 && game->endgame != 0)
		ft_restart(game);
	else if (keycode == 13 && game->endgame == 0)
		ft_up(game);
	else if (keycode == 1 && game->endgame == 0)
		ft_down(game);
	else if (keycode == 2 && game->endgame == 0)
		ft_right(game);
	else if (keycode == 0 && game->endgame == 0)
		ft_left(game);
	else
		return (0);
	game->enemy->move = 1;
	return (0);
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
			ft_enemy_move_cdt1(game, i);
		else
			ft_enemy_move_cdt2(game, i);
		i++;
	}
}

void	ft_print_enemy(t_game *game, int x, int y)
{
	int	i;
	int	posx;
	int	posy;

	posx = ft_position(WINDOW_WIDTH);
	posy = ft_position(WINDOW_LENGTH);
	i = 0;
	while (i < game->enemy->nbenemy)
	{
		if (game->player->x + 1 + x - posx == game->enemy->x[i]
			&& game->player->y + 1 + y - posy == game->enemy->y[i])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->sprite->enemy[game->enemy->dir[i]], 64 * x
				+ game->player->movex * 32, 64 * y + game->player->movey * 32);
		}
		i++;
	}
}

void	ft_enemy_move_cdt2(t_game *game, int i)
{
	if (game->player->y > game->enemy->y[i]
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
	else if (game->map[game->enemy->y[i]][game->enemy->x[i] - 1] != '1')
	{
		game->enemy->dir[i] = 2;
		game->enemy->x[i]--;
	}
	else if (game->player->x > game->enemy->x[i]
		&& game->map[game->enemy->y[i]][game->enemy->x[i] + 1] != '1')
	{
		game->enemy->dir[i] = 3;
		game->enemy->x[i]++;
	}
}

void	ft_end(t_game *game)
{
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
