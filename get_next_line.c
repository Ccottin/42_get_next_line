/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:08:26 by ccottin           #+#    #+#             */
/*   Updated: 2021/09/09 15:20:40 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return(char **line, char **leftover, int mark)
{
	if (mark == -1)
	{
		if (*leftover)
			free(*leftover);
		if (*line)
			free(*line);
		return (NULL);
	}
	else
	{
		if (!(*leftover) && mark == -2 && ft_strcmp(*line, "") == 0)
		{
			free(*line);
			*line = NULL;
		}
		return (*line);
	}
}

char	*cut_leftover(char *line, int bsn, char **leftover)
{
	int	i;
	int	y;

	y = ft_strlen(line, bsn);
	if (y != 0 && bsn != -1)
	{
		*leftover = ft_calloc(y, 1);
		if (!leftover)
			return (NULL);
		i = 0;
		bsn++;
		while (i < y)
		{
			(*leftover)[i] = line[bsn];
			i++;
			bsn++;
		}
		bsn = bsn - i;
		line[bsn] = '\0';
	}
	return (line);
}

int	get_str(int fd, char **str)
{
	int		ret;

	*str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (-1);
	ret = read(fd, *str, BUFFER_SIZE);
	return (ret);
}

int	get_line(int fd, char **line)
{
	char	*str;
	int		mark;
	int		i;

	mark = -1;
	i = 0;
	while (mark != 0)
	{
		while ((*line)[i] != '\n' && i < ft_strlen(*line, 0))
			i++;
		if ((*line)[i] == '\n')
			mark = 0;
		else
		{
			mark = get_str(fd, &str);
			if (mark == -1)
				return (-1);
			*line = ft_strcat(*line, str);
			if (mark == 0)
				i = -2;
		}
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	int			i;

	line = "";
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) == -1)
		return (NULL);
	line = NULL;
	if (!leftover)
		get_str(fd, &line);
	else
		line = ft_copy(&leftover);
	if (line == NULL)
		return (ft_return(&line, &leftover, -1));
	i = get_line(fd, &line);
	if (i == -1)
		return (ft_return(&line, &leftover, -1));
	if (i == -2)
		return (ft_return(&line, &leftover, -2));
	line = cut_leftover(line, i, &leftover);
	if (line == NULL)
		return (ft_return(&line, &leftover, -1));
	return (ft_return(&line, &leftover, 1));
}
