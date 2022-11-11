/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:26:04 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/07 16:50:44 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*temporary;
	int			flag;
	int			size;

	size = 0;
	temporary = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (temporary);
	while (1)
	{
		flag = 1;
		if (!buffer[0])
			flag = read(fd, buffer, BUFFER_SIZE);
		size += search_for_size(buffer, 10);
		if (flag > 0)
			temporary = join_buffer(temporary, buffer, size);
		if (flag <= 0 || search_for_bl(buffer) == 0)
			break ;
	}
	return (temporary);
}
