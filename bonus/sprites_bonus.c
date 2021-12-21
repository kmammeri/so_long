/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:27:55 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 16:32:23 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_sprite_vertical_move(t_game *game)
{
	int			width[1];
	int			height[1];

	if (game->player->move % 2 == 0)
		game->sprite->pikachu[0] = mlx_xpm_file_to_image(game->mlx,
				"sprite/pikachu_south_right_feet.xpm", width, height);
	else
		game->sprite->pikachu[0] = mlx_xpm_file_to_image(game->mlx,
				"sprite/pikachu_south_left_feet.xpm", width, height);
	game->sprite->pikachu[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/pikachu_move_north.xpm", width, height);
}

void	ft_sprite_horizontal_move(t_game *game)
{
	int			width[1];
	int			height[1];

	if (game->player->move % 2 == 0)
	{
		game->sprite->pikachu[2] = mlx_xpm_file_to_image(game->mlx,
				"sprite/pikachu_est_right_feet.xpm", width, height);
		game->sprite->pikachu[3] = mlx_xpm_file_to_image(game->mlx,
				"sprite/pikachu_ouest_right_feet.xpm", width, height);
	}
	else
	{
		game->sprite->pikachu[2] = mlx_xpm_file_to_image(game->mlx,
				"sprite/pikachu_est_left_feet.xpm", width, height);
		game->sprite->pikachu[3] = mlx_xpm_file_to_image(game->mlx,
				"sprite/pikachu_ouest_left_feet.xpm", width, height);
	}
}

void	ft_sprite2(t_game *game)
{
	int			width[1];
	int			height[1];

	game->sprite->end = mlx_xpm_file_to_image(game->mlx,
			"sprite/raichu.xpm", width, height);
	game->sprite->top_left_corner = mlx_xpm_file_to_image(game->mlx,
			"sprite/top_left_corner-2.xpm", width, height);
	game->sprite->top_middle_screen = mlx_xpm_file_to_image(game->mlx,
			"sprite/top_middle_screen-2.xpm", width, height);
	game->sprite->top_right_corner = mlx_xpm_file_to_image(game->mlx,
			"sprite/top_right_corner-2.xpm", width, height);
	game->sprite->wasted = mlx_xpm_file_to_image(game->mlx,
			"sprite/wasted.xpm", width, height);
	game->sprite->success = mlx_xpm_file_to_image(game->mlx,
			"sprite/success.xpm", width, height);
}

void	ft_sprite3(t_game *game)
{
	int			width[1];
	int			height[1];

	game->sprite->bottom_left_corner = mlx_xpm_file_to_image(game->mlx,
			"sprite/bottom_left_corner-2-2.xpm", width, height);
	game->sprite->bottom_middle_screen = mlx_xpm_file_to_image(game->mlx,
			"sprite/bottom_middle_screen-2.xpm", width, height);
	game->sprite->bottom_right_corner = mlx_xpm_file_to_image(game->mlx,
			"sprite/bottom_right_corner-2.xpm", width, height);
	game->sprite->left_middle_screen = mlx_xpm_file_to_image(game->mlx,
			"sprite/left_middle_screen-2.xpm", width, height);
	game->sprite->right_middle_screen = mlx_xpm_file_to_image(game->mlx,
			"sprite/right_middle_screen-2.xpm", width, height);
	game->sprite->enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/enemy_south.xpm", width, height);
	game->sprite->enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/enemy_north.xpm", width, height);
	game->sprite->enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/enemy_left.xpm", width, height);
	game->sprite->enemy[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/enemy_right.xpm", width, height);
	game->sprite->logo_gameboy = mlx_xpm_file_to_image(game->mlx,
			"sprite/logo_gameboy.xpm", width, height);
}

void	ft_sprite(t_game *game)
{
	int			width[1];
	int			height[1];

	game->sprite->floor = mlx_xpm_file_to_image(game->mlx,
			"sprite/ground.xpm", width, height);
	game->sprite->wall = mlx_xpm_file_to_image(game->mlx,
			"sprite/tree_wall.xpm", width, height);
	game->sprite->exit = mlx_xpm_file_to_image(game->mlx,
			"sprite/exit.xpm", width, height);
	game->sprite->collectible = mlx_xpm_file_to_image(game->mlx,
			"sprite/collectible.xpm", width, height);
	game->sprite->pikachu[0] = mlx_xpm_file_to_image(game->mlx,
			"sprite/pikachu_sud.xpm", width, height);
	game->sprite->pikachu[1] = mlx_xpm_file_to_image(game->mlx,
			"sprite/pikachu_nord.xpm", width, height);
	game->sprite->pikachu[2] = mlx_xpm_file_to_image(game->mlx,
			"sprite/pikachu_est.xpm", width, height);
	game->sprite->pikachu[3] = mlx_xpm_file_to_image(game->mlx,
			"sprite/pikachu_ouest.xpm", width, height);
	ft_sprite2(game);
	ft_sprite3(game);
}
