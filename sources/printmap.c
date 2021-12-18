/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:58:05 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/17 14:07:09 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_printmapcnd1(t_game *game, int x, int y)
{
	int	posx;
	int	posy;

	posx = ft_position(WINDOW_WIDTH);
	posy = ft_position(WINDOW_LENTH);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->floor, x * 64, y * 64);
	if (game->map[game->player->y + 1 + y - posy][game->player->x
		+ 1 + x - posx] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite->wall, 64 * x, 64 * y);
	else if (game->map[game->player->y + 1 + y - posy][game->player->x
		+ 1 + x - posx] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite->collectible, 64 * x, 64 * y);
	else if (game->map[game->player->y + 1 + y - posy][game->player->x
		+ 1 + x - posx] == 'E' && game->nbcollectible == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite->exit, 64 * x, 64 * y);
}

void	ft_printmapcnd2(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->floor, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite->wall, 64 * x, 64 * y);
}

void	ft_printmapcnd3(t_game *game, int posx, int posy)
{
	if (game->endgame == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite->pikachu
		[game->player->dir], (posx - 1) * 64, (posy - 1) * 64);
		mlx_key_hook(game->window, ft_press_key, game);
	}
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite->end, (posx - 1) * 64, (posy - 1) * 64);
}

void	ft_printmaploop(t_game *game, int posx, int posy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WINDOW_LENTH / 64)
	{
		while (x < WINDOW_WIDTH / 64)
		{
			if (game->player->x + x + 1 - posx >= 0 && game->player->y + y + 1
				- posy >= 0 && game->player->x + 1 + x - posx < game->width && \
				game->player->y + 1 + y - posy < game->lenth)
				ft_printmapcnd1(game, x, y);
			else
				ft_printmapcnd2(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_printmap(t_game *game)
{
	int			x;
	int			y;
	int			posx;
	int			posy;

	x = 0;
	y = 0;
	posx = ft_position(WINDOW_WIDTH);
	posy = ft_position(WINDOW_LENTH);
	ft_sprite(game);
	ft_printmaploop(game, posx, posy);
	ft_printmapcnd3(game, posx, posy);
}
