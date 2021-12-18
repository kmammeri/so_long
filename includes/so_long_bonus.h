/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:06:13 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/18 19:56:38 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../opengl/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 1
# define  WINDOW_LENTH 576
# define  WINDOW_WIDTH 576

typedef struct s_sprite
{
	void	*floor;
	void	*wall;
	void	*pikachu[4];
	void	*exit;
	void	*end;
	void	*collectible;

}				t_sprite;

typedef struct s_player
{
	int	x;
	int	y;
	int	dir;
	int	move;
	int movex;
	int movey;
}		t_player;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*window;
	int			lenth;
	int			width;
	int			nbmc;
	int			nbcollectible;
	int			nbexit;
	int			endgame;
	int			timer;
	int			anime;
	t_sprite	*sprite;
	t_player	*player;
}			t_game;

char	*get_next_line(int fd, t_game *game);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int chr);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_printmap(t_game *game);
int		ft_close(t_game *game);
void	ft_initmap(t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
int		ft_press_key(int keycode, t_game *game);
int		ft_position(int size);
t_game	*ft_mapping(char *doc, t_game *game);
void	ft_checkwall(t_game *game, int i, int j);
void	ft_checkchar(t_game *game);
void	ft_sprite(t_game *game);
void	ft_sprite_horizontal_move(t_game *game);
void	ft_sprite_vertical_move(t_game *game);
int		ft_delay(t_game *game);
void	ft_end(t_game *game);

#endif