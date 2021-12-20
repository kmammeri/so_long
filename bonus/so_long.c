/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:52:55 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/20 20:29:16 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	game->sprite->end = mlx_xpm_file_to_image(game->mlx,
			"sprite/raichu.xpm", width, height);
	game->sprite->top_left_corner = mlx_xpm_file_to_image(game->mlx,
			"sprite/top_left_corner-2.xpm", width, height);
	game->sprite->top_middle_screen = mlx_xpm_file_to_image(game->mlx,
			"sprite/top_middle_screen-2.xpm", width, height);
	game->sprite->top_right_corner = mlx_xpm_file_to_image(game->mlx,
			"sprite/top_right_corner-2.xpm", width, height);
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
}

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

int	ft_position(int size)
{
	int	pos;

	if (size % 128 == 0)
		pos = size / 128;
	else
		pos = size / 128 + 1;
	return (pos);
}

int	main(int argc, char **argv)
{
	int			endargv;
	t_game		*game;

	endargv = 0;
	if (argc != 2)
		exit(0);
	endargv = ft_strlen(argv[1]);
	if (argv[1][endargv - 4] != '.' || argv[1][endargv - 3] != 'b' \
	|| argv[1][endargv - 2] != 'e' || argv[1][endargv - 1] != 'r')
	{
		printf("Error!\nThe map does not end with a '.ber'\n");
		exit(0);
	}	
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	game = ft_mapping(argv[1], game);
	game->window = mlx_new_window(game->mlx,
			WINDOW_WIDTH, WINDOW_LENTH, "so_long");
	ft_printmap(game);
	mlx_loop_hook(game->mlx, ft_delay, game);
	mlx_hook(game->window, 17, 1L << 17, ft_close, game);
	mlx_loop(game->mlx);
}
