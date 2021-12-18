/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:55:31 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/16 10:55:33 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_checkline(t_game *game, char *txt)
{
	int	lentxt;

	lentxt = ft_strlen(txt);
	if (txt && game->width == 0)
		game->width = lentxt;
	if (game->width != lentxt && txt)
	{
		write(1, "Error! the map is not a rectangle\n", 34);
		exit(0);
	}
}

char	*ft_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (NULL);
	len = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_mem(char *str)
{
	int		len;
	int		start;
	char	*memnextline;
	int		i;

	len = ft_strlen(ft_strchr(str, '\n'));
	i = 0;
	if (len == 0)
	{
		return (NULL);
	}
	start = ft_strlen(str) - len;
	memnextline = malloc(len + 1);
	if (!memnextline)
		return (NULL);
	while (i < len)
	{
		memnextline[i] = str[start + 1];
		i++;
		start++;
	}
	memnextline[i] = '\0';
	return (memnextline);
}

char	*ft_read(int fd, char *mem)
{
	char	*str;
	char	*tmp;
	int		stop;

	stop = 1;
	str = NULL;
	if (mem)
		str = ft_strjoin(mem, str);
	while (!ft_strchr(str, '\n') && stop > 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		stop = read(fd, tmp, BUFFER_SIZE);
		if (stop == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[stop] = '\0';
		if (stop != 0)
			str = ft_strjoin(str, tmp);
	}
	if (stop == 0)
		free (tmp);
	return (str);
}

char	*get_next_line(int fd, t_game *game)
{
	static char	*mem;
	char		*str;
	char		*txt;

	txt = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	if (mem && ft_strchr(mem, '\n'))
		str = mem;
	else
		str = ft_read(fd, mem);
	txt = ft_line(str);
	mem = ft_mem(str);
	if (str)
		free(str);
	ft_checkline(game, txt);
	return (txt);
}
