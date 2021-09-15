/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:03:32 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/14 14:54:39 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char	*s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char	*s, int c);

char	*get_next_line(int fd);

char	*str_process(char *str);

char	*ft_select(char	*buf);

char	*ft_select2(char *buf);

int		cheker(int	*ret, char	**str);

#endif
