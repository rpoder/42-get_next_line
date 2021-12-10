/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:00:03 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/10 19:51:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*ret;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("impossible de lire le fichier");
	}
	ret = get_next_line(fd);
	printf("ligne: %s", ret);
	printf("\n\n\n");
	ret = get_next_line(fd);
	printf("ligne: %s", ret);
	close(fd);
	return (0);

	// char to_trim[20] = "Salut,\ntrimmez moi";
	// printf("str trimmee =%s", ft_trim_line(to_trim));
}
