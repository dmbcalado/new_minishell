/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridges.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:20:36 by dmendonc       #+#    #+#             */
/*   Updated: 2022/11/08 15:43:56 by dmendonc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	bridge_infiles(t_data *data, int index, int last)
{
	int	count;
	int	i;
	int	ret;
	
	i = 0;
	count = -1;
	while(++count <= index)
	{
		while(data->par_line[i])
		{
			ret = redir_detector (data, data->par_line[i]);
			if (ret == 1)
			{
				i++;
				break;
			}
			if (ret > 1)
			{
				if (ret < 4 && i != last && count == index)
				{
					if(open(data->par_line[i + 1], O_RDONLY) < 0)
					{
						printf("Error: the file %s does not exist.", data->par_line[i + 1]);
						return (-1);
					}
				}
			}
			i++;
		}
	}
	return (1);
}

int	bridge_outfiles(t_data *data, int index, int last)
{
	int	count;
	int	i;
	int	ret;

	i = 0;
	count = -1;
	while (++count <= index)
	{
		while (data->par_line[i])
		{
			ret = redir_detector (data, data->par_line[i]);
			if (ret == 1)
			{
				i++;
				break ;
			}
			if (ret > 1)
			{
				if (ret > 3 && i != last && count == index)
				{
					printf("%d entrou para dar bridge a %s\n", i, data->par_line[i + 1]);
					if (open(data->par_line[i + 1], O_CREAT | O_RDWR | O_TRUNC, 777) < 0)
						return (-1);
				}
			}
			i++;
		}
	}
	return (1);
}
