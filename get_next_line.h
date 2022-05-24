/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:11:03 by ccottin           #+#    #+#             */
/*   Updated: 2021/09/09 15:20:37 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str, int start);
char	*get_next_line(int fd);
char	*ft_copy(char **leftover);
char	*ft_calloc(int size, int mem);
char	*ft_strcat(char *s1, char *s2);

#endif
