/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:03:23 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/14 15:24:26 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#if BUFFER_SIZE <= 0
# define	BUFFER_SIZE 0
#endif

char	*ft_select(char	*buf)
{
	int		i;
	char	*dest;

	i = 0;
	if (buf[0] == 0)
		return (NULL);
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	dest[i] = 0;
	while (i-- > 0)
		dest[i] = buf[i];
	return (dest);
}

char	*ft_select2(char *buf)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(*dest) * (ft_strlen(buf) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (buf && buf[i])
		dest[j++] = buf[++i];
	dest[j] = 0;
	if (j == 0)
	{
		free(dest);
		dest = NULL;
		return (NULL);
	}
	return (dest);
}

char	*str_process(char *s1)
{
	char	*s2;

	s2 = ft_select2(s1);
	free(s1);
	s1 = s2;
	return (s1);
}

int	cheker(int	*ret, char **str)
{
	if (*ret == 0 && !*str)
	{
		free(str);
		*str = 0;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*str = NULL;
	char		*line;

	ret = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && str == 0) || ret == -1)
			return (NULL);
		buf[ret] = 0;
		line = str;
		str = ft_strjoin(str, buf);
		free(line);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (cheker(&ret, &str))
		return (NULL);
	line = ft_select(str);
	str = str_process(str);
	return (line);
}
