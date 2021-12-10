/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:31 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/10 20:29:36 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_rest(char *to_trim)
{
	char	*tmp;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
		printf("to trim = %s\n", to_trim);

	while (to_trim[i] != '\n' && to_trim[i])
		i++;
	if (!to_trim[i])
	{
		free(to_trim);
		return (NULL);
	}
	len = ft_strlen(to_trim) - i;
	printf("len trim reste = %zu\n", len);
	tmp = (char *)malloc((len + 1) * sizeof(char));
	i++;
	while (j < len)
	{
		tmp[j] = to_trim[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	printf("trimmed = %s\n", tmp);
	free(to_trim);
	return (tmp);
}

char	*ft_trim_line(char	*to_trim)
{
	char	*tmp;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (to_trim[len] != '\n' && to_trim[len])
		len++;
	if (to_trim[len] == '\n')
		len++;
	printf("len trim line = %d\n", len);
	tmp = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		tmp[i] = to_trim[i];
		i++;
	}
	tmp[len] = '\0';
	free(to_trim);
	return (tmp);
}

char	*ft_read_line(int fd, char *reste)
{
	char	*buf;
	int		ret;

	ret = 1;
	printf("reste=|%s|\n", reste);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

	while (!ft_strchr(reste, '\n') && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("buf= |%s|\nret = %d\n", buf, ret);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		printf("reste a join |%s|\n", reste);
		reste = ft_strjoin(reste, buf);
	}
	free(buf);
	return (reste);
}

char	*get_next_line(int fd)
{
	static char	*reste;
	char		*ligne;

	reste = ft_read_line(fd, reste);
	ligne = ft_trim_line(reste);
	reste = ft_trim_rest(reste);
	//printf("reste|%s|\n", reste);
	return (ligne);
}
