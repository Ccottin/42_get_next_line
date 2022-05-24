/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:12:56 by ccottin           #+#    #+#             */
/*   Updated: 2021/09/09 15:02:24 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str, int start)
{
	int	i;

	i = start;
	while (str[i])
		i++;
	return (i - start);
}

char	*ft_copy(char **leftover)
{
	char	*ret;
	int		i;

	ret = ft_calloc(ft_strlen(*leftover, 0) + 1, 1);
	if (!ret)
		return (NULL);
	i = 0;
	while ((*leftover)[i])
	{
		ret[i] = (*leftover)[i];
		i++;
	}
	free(*leftover);
	*leftover = NULL;
	return (ret);
}

char	*ft_calloc(int size, int mem)
{
	char	*str;
	int		i;

	str = malloc(size * mem);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size * mem)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_calloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1, 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		ret[i] = s2[y];
		i++;
		y++;
	}
	free(s1);
	free(s2);
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	if (s1[i] > s2[i] || s1[i] < s2[i])
		return (1);
	else
		return (0);
}
