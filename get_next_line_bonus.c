/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:06:04 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/12 12:07:34 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_before_cariage(char *s)
{
	char	*res;
	int		i;
	int		len_s;

	i = 0;
	len_s = ft_strlen(s);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != 0)
		res = malloc(sizeof(char) * ((len_s - ft_strlen_after_cariage(s)) + 2));
	else
		res = malloc(sizeof(char) * ((len_s - ft_strlen_after_cariage(s)) + 1));
	i = 0;
	if (!res || !s)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] != 0)
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}

char	*ft_after_cariage(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen_after_cariage(s) + 1));
	if (!res || !s)
		return (free(s), s = NULL, NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == 0)
		return (free(res), res = NULL, free(s), s = NULL, NULL);
	i++;
	while (s[i])
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = 0;
	return (free(s), s = NULL, res);
}

char	*ft_reader(int fd, char *buf)
{
	char	*temp[OPEN_MAX];
	int		len_read;

	temp[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp[fd])
		return (free(buf), buf = NULL, NULL);
	len_read = 1;
	while (!ft_strchr(buf, '\n') && len_read != 0)
	{
		len_read = read(fd, temp[fd], BUFFER_SIZE);
		if (len_read == -1)
			return (free(buf), buf = NULL, \
			free(temp[fd]), temp[fd] = NULL, NULL);
		temp[fd][len_read] = 0;
		buf = ft_strjoin(buf, temp[fd]);
	}
	return (free(temp[fd]), temp[fd] = NULL, buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd >= OPEN_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buf[fd])
			free(buf[fd]);
		return (NULL);
	}
	buf[fd] = ft_reader(fd, buf[fd]);
	if (!buf[fd] || buf[fd][0] == 0)
		return (free(buf[fd]), buf[fd] = NULL, NULL);
	line = ft_before_cariage(buf[fd]);
	if (!line)
		return (free(buf[fd]), buf[fd] = NULL, buf[fd]);
	buf[fd] = ft_after_cariage(buf[fd]);
	if (!buf[fd])
		return (free(buf[fd]), buf[fd] = NULL, line);
	return (line);
}
