/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:00:03 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/30 17:03:16 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("impossible de lire le fichier");
	}
	get_next_line(fd);
	close(fd);

	return (0);
}
