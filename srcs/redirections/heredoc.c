/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:01:46 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/08 14:55:00 by dmendonc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	heredoc(t_data *data, int index)
{
	int		len;
	char	*buffer;

	data->ids.inp_list[index] = open(".heredoc_tmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if( data->ids.inp_list[index] < 2)
	{
		printf("something is going terribly wrong.\n");
		return ;
	}
	len = len_str(data->redir.hdoc_key);
	printf("len : %d\n", len);
	while (1)
	{
		write(1, "> ", 2);
		buffer = get_next_line(0);
		if (buffer)
		{
			if (len == len_str(buffer) - 1)
			{
				if(compare_key(data, buffer, len) > 0)
				{
					free (buffer);
					break ;
				}
			}
			write(data->ids.inp_list[index], buffer, len_str(buffer));
			free (buffer);
		}
	}
	data->ids.inp_list[index] = open(".heredoc_tmp", O_RDONLY);
	if (data->ids.inp_list[index] < 0)
		write(2, "Error on heredoc. Exiting.\n", 27);
}

int	compare_key(t_data *data, char *buffer, int len)
{
	int	j;

	j = -1;
	while(data->redir.hdoc_key[++j])
		if (buffer[j] != data->redir.hdoc_key[j])
			break ;
	if (j == len)
		return (1);
	return	(0);
}