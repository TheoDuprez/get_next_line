/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:06:09 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/09 12:50:41 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

// char	*ft_reader(int fd);
char	*ft_reader(int fd, char *buf);
int		ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);

int		ft_is_cariage(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_after_cariage(const char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
