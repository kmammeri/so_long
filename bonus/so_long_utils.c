/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:52:55 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/18 19:57:29 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)chr)
			return ((char *)str + i);
		i++;
	}
	if (str && (str[i] == (char)chr))
		return ((char *)str + i);
	return (NULL);
}

void	ft_destroy(t_game *game)
{
	if (game->sprite->collectible)
		mlx_destroy_image(game->mlx, game->sprite->collectible);
	if (game->sprite->wall)
		mlx_destroy_image(game->mlx, game->sprite->wall);
	if (game->sprite->pikachu[0])
		mlx_destroy_image(game->mlx, game->sprite->pikachu[0]);
	if (game->sprite->pikachu[1])
		mlx_destroy_image(game->mlx, game->sprite->pikachu[1]);
	if (game->sprite->pikachu[2])
		mlx_destroy_image(game->mlx, game->sprite->pikachu[2]);
	if (game->sprite->pikachu[3])
		mlx_destroy_image(game->mlx, game->sprite->pikachu[3]);
	if (game->sprite->end)
		mlx_destroy_image(game->mlx, game->sprite->end);
	if (game->sprite->exit)
		mlx_destroy_image(game->mlx, game->sprite->exit);
	if (game->sprite->floor)
		mlx_destroy_image(game->mlx, game->sprite->floor);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}

int	ft_close(t_game *game)
{
	int	i;

	i = 0;
	ft_destroy(game);
	if (game->player)
		free(game->player);
	if (game->sprite)
		free(game->sprite);
	while (game->map && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	if (game)
		free(game);
	exit(0);
}

void	ft_initmap(t_game *game)
{
	game->map = malloc(sizeof(char *) + 1);
	if (!game->map)
		ft_close(game);
	game->sprite = malloc(sizeof(t_sprite));
	if (!game->sprite)
		ft_close(game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_close(game);
	game->window = 0;
	game->endgame = 0;
	game->lenth = 0;
	game->width = 0;
	game->nbmc = 0;
	game->nbcollectible = 0;
	game->nbexit = 0;
	game->player->x = 0;
	game->player->y = 0;
	game->player->move = 0;
	game->player->dir = 0;
	game->timer = 0;
	game->player->movex = 0;
	game->player->movey = 0;
	game->sprite->floor = NULL;
}
