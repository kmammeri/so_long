/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:52:55 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/21 19:23:53 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_position(int size)
{
	int	pos;

	if (size % 128 == 0)
		pos = size / 128;
	else
		pos = size / 128 + 1;
	return (pos);
}

void	ft_aftermain(t_game *game)
{
	game->endgame = 0;
	if (game->endgame == 0)
	{
		game->mlx = mlx_init();
		game = ft_mapping(game->arg, game);
		game->window = mlx_new_window(game->mlx,
				WINDOW_WIDTH, WINDOW_LENGTH, "so_long");
		ft_printmap(game);
		mlx_loop_hook(game->mlx, ft_delay, game);
		mlx_hook(game->window, 17, 1L << 17, ft_close, game);
	}
	mlx_loop(game->mlx);
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
	game->arg = argv[1];
	ft_aftermain(game);
}
