/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:55:51 by kmammeri          #+#    #+#             */
/*   Updated: 2021/12/17 16:53:03 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;
	int		i;
	int		count;

	count = elementCount * elementSize;
	str = malloc(count);
	if (!str)
		return (NULL);
	i = 0;
	while (count-- > 0)
		str[i++] = 0;
	return (str);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(src);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	if (src)
		free((char *)src);
	return (str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendest;
	size_t	lensrc;

	j = 0;
	lendest = ft_strlen(dest);
	i = lendest;
	lensrc = ft_strlen(src);
	if (size == 0 || size < i)
	{	
		if (src)
			free((char *)src);
		return (size + lensrc);
	}
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (src)
		free((char *)src);
	dest[i] = '\0';
	return (lendest + lensrc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			len;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcat((char *)str, (char *)s1, ft_strlen(s1) + 2);
	ft_strlcat((char *)str, (char *)s2, len + 2);
	return (str);
}
