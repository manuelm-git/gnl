/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manumart <manumart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:36:17 by manumart          #+#    #+#             */
/*   Updated: 2023/05/05 21:53:58 by manumart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (saved[i])
			saved[i++] = 0;
		return (NULL);
	}
	while (saved[0] || read(fd, saved, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, saved);
		if (ft_clear(saved))
			break ;
	}
	return (line);
}
