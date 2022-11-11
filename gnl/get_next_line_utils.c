/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:30:54 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/11 15:00:32 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_for_size(const char *buffer, int chr)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == chr)
			return (++i);
		i++;
	}
	return (i);
}

int	search_for_bl(char *buffer)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 1;
	while (buffer[i])
	{
		if (flag == 1 && buffer[i] == 10)
			flag = 0;
		else if (flag == 0)
			buffer[j++] = buffer[i];
		buffer[i++] = 0;
	}
	return (flag);
}

char	*join_buffer(char *temporary, char *buff, int size)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	j = 0;
	new_temp = malloc((size + 1) * sizeof(char));
	while (temporary && temporary[i])
	{
		new_temp[i] = temporary[i];
		i++;
	}
	while (buff[j])
	{
		new_temp[i++] = buff[j];
		if (buff[j++] == 10)
			break ;
	}
	new_temp[i] = '\0';
	if (temporary)
		free(temporary);
	return (new_temp);
}
