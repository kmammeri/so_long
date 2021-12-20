/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:48:49 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/20 21:26:36 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_countchar(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P' && game->nbmc == 0)
	{
		game->nbmc++;
		game->map[i][j] = '0';
		game->player->x = j;
		game->player->y = i;
	}
	else if (game->map[i][j] == 'P')
			game->enemy->nbenemy++;
	else if (game->map[i][j] == 'E')
		game->nbexit++;
	else if (game->map[i][j] == 'C')
		game->nbcollectible++;
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
	{
		write(1, "Error! wrong character in map\n", 30);
		exit (0);
	}
}

void	ft_countinmap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->lenth)
	{
		while (j < game->width)
		{
			ft_countchar(game, i, j);
			ft_checkwall(game, i, j);
			j++;
		}
		if (game->width != j)
		{
			write(1, "Error! the map is not a rectangle\n", 34);
			exit(0);
		}
		j = 0;
		i++;
	}
	ft_checkchar(game);
}

void	ft_mapintabcut(int j, t_game *game, char **tmp)
{
	while (j >= 0)
	{
		tmp[j] = game->map[j];
		j--;
	}
	free(game->map);
	game->map = tmp;
}

void	ft_mapintab(t_game *game, char *tmp, int i, int fd)
{
	int		j;
	char	**maptmp;

	while (tmp)
	{
		i++;
		tmp = get_next_line(fd, game);
		if (tmp)
		{
			j = i;
			maptmp = malloc(sizeof(char **) * (i + 2));
			if (!maptmp)
				ft_close(game);
			maptmp[i + 1] = NULL;
			maptmp[i] = tmp;
			j--;
			ft_mapintabcut(j, game, maptmp);
		}
	}
	game->lenth = i;
}

t_game	*ft_mapping(char *doc, t_game *game)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(doc, O_RDONLY);
	ft_initmap(game);
	tmp = get_next_line(fd, game);
	if (!tmp)
	{
		write(1, "Error invalide map\n", 19);
		exit (0);
	}
	game->map[i] = tmp;
	ft_mapintab(game, tmp, i, fd);
	ft_countinmap(game);
	ft_init_enemy(game);
	return (game);
}
