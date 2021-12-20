/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:46 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/20 20:58:18 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_delay(t_game *game)
{
	if (game->anime == 1)
	{
		ft_printmap(game);
		if (game->timer < 5)
			game->timer++;
		else
		{
			ft_check_enemy(game);
			ft_sprite(game);
			ft_printmap(game);
			if (game->player->move % 2 == 0)
				ft_enemy_move(game);
			ft_check_enemy(game);
			game->player->movex = 0;
			game->player->movey = 0;
			game->anime = 0;
			game->timer = 0;
			ft_check_enemy(game);
			ft_printmap(game);
		}
	}
	if (game->enemy->move >= 1)
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

void	ft_frame(t_game *game)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	str = ft_itoa(game->player->move);
	while (y < WINDOW_LENTH / 64)
	{
		while (x < WINDOW_WIDTH / 64)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->top_middle_screen, 64* x, 0);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->bottom_middle_screen, 64 * x, WINDOW_LENTH - 62);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->left_middle_screen, 0, 64 * y);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->right_middle_screen, WINDOW_WIDTH - 64, 64 * y);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->top_left_corner, 0, 0);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->top_right_corner, WINDOW_WIDTH - 64, 0);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->bottom_left_corner, 0, WINDOW_LENTH - 64);
			mlx_put_image_to_window(game->mlx, game->window, game->sprite->bottom_right_corner, WINDOW_WIDTH - 64, WINDOW_LENTH - 64);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(game->mlx, game->window, 64, 32, 0xff, "Score :");
	mlx_string_put(game->mlx, game->window, 120, 32, 0xff, str);
}
