/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:31 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/30 18:30:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_trim(char *to_trim)
{
	char	*tmp;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (to_trim[i] != '\n' && to_trim[i])
		i++;
	len = ft_strlen(to_trim) - i - 1;
	printf("len = %zu\n", len);
	tmp = (char *)malloc(len * sizeof(char));
	i++; //sauter \n
	while (j < len)
	{
		tmp[j] = to_trim[i];
		i++;
		j++;
	}
	tmp[len] = '\0';
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
	tmp = (char *)malloc((len + 1) * sizeof(char));
	while (i <= len)
	{
		tmp[i] = to_trim[i];
		i++;
	}
	tmp[len + 1] = '\0';
	//free(to_trim);
	return (tmp);
}

char	*ft_read_line(int fd, char *reste)
{
	char	*buf;
	char	*tmp;
	int		ret;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		reste = ft_strjoin(reste, buf);
	}
	free(buf);
	return (reste);
}

char	*get_next_line(int fd)
{
	static char	* reste;
	
	reste = ft_read_line(fd, reste);
	printf("reste|%s|\n", reste);
	return (NULL);
}
