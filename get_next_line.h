/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:50:40 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/30 18:30:37 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //A SUPPRIMER

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUFFER_SIZE 12

char	*get_next_line(int fd);
char *ft_trim(char *to_trim);
char	*ft_trim_line(char	*to_trim);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *str);
#endif
