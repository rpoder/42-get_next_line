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

int	count_line(void)
{
	static int	i = 0;

	i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static int	i = 0;
	int	j;
	char		buf[BUFFER_SIZE + 1];
	char	*tmp;

	tmp = (char *)ft_calloc(1, sizeof(char));

	printf("buf:%s\n",buf);

	while (!ft_strchr(buf, '\n'))
	{
		printf("boucle\n");
		read(fd, buf, BUFFER_SIZE);
		printf("buf:%s\n",buf);
		tmp = ft_strjoin(tmp, buf);
	}

	printf("tmp:%s\n", tmp);
	return (NULL);
}
