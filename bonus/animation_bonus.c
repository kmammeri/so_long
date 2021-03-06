/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:46 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 19:27:47 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_animation(t_game *game)
{
	ft_printmap(game);
	if (game->timer < 5)
		game->timer++;
	else
	{
		ft_sprite(game);
		if (GAME_DIFFICULTY == 0)
		{
			if (game->player->move % 2 == 0)
				ft_enemy_move(game);
		}
		else
			ft_enemy_move(game);
		game->player->movex = 0;
		game->player->movey = 0;
		game->anime = 0;
		game->timer = 0;
		ft_check_enemy(game);
		ft_printmap(game);
	}
}

int	ft_delay(t_game *game)
{
	if (game->anime == 1 && game->endgame == 0)
		ft_animation(game);
	if (game->enemy->move >= 1 && game->endgame == 0)
	{
		if (game->enemy->move < 9000)
			game->enemy->move++;
		else
		{
			ft_enemy_move(game);
			ft_printmap(game);
			ft_check_enemy(game);
			game->enemy->move = 1;
		}
	}
	return (0);
}

void	ft_frame2(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->top_middle_screen, 64 * x, 0);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->bottom_middle_screen, 64 * x, WINDOW_LENGTH - 62);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->left_middle_screen, 0, 64 * y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->right_middle_screen, WINDOW_WIDTH - 64, 64 * y);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->top_left_corner, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->top_right_corner, WINDOW_WIDTH - 64, 0);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->bottom_left_corner, 0, WINDOW_LENGTH - 64);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->bottom_right_corner,
		WINDOW_WIDTH - 64, WINDOW_LENGTH - 64);
}

void	ft_frame_info(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player->move);
	if (!str)
		ft_close(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->logo_gameboy,
		(WINDOW_WIDTH / 2) - 160, WINDOW_LENGTH - 61);
	mlx_string_put(game->mlx, game->window, 64, 32, 0xff, "Score :");
	mlx_string_put(game->mlx, game->window, 120, 32, 0xff, str);
	if (game->endgame == 1)
	{
		mlx_string_put(game->mlx, game->window,
			150, 21, 0x0000ff00, "SUCCESS!");
		mlx_string_put(game->mlx, game->window,
			150, 32, 0xffffff00, "Press esc to quit");
		mlx_string_put(game->mlx, game->window,
			150, 43, 0xffffff00, "Press r to restart");
	}
	if (str)
		free(str);
}

void	ft_frame(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < WINDOW_LENGTH / 64)
	{
		while (x < WINDOW_WIDTH / 64)
		{
			ft_frame2(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	ft_frame_info(game);
}
