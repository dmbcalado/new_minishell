/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_built.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:07:12 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/10 02:36:36 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void    parse_builtin(t_data *data, int i, int index)
{
	int	j;
	int	l;
	int	len;

	l = -1;
	len = len_str(data->par_line[i]);
	while (data->built.builtins[++l])
	{
		j = -1;
		while (data->built.builtins[l][++j])
		{
		 	if (data->par_line[i][j] != data->built.builtins[l][j])
				break ;
		}
		if(j == len)
		{
			builting(data, i, index);
			break ;
		}
	}
}

void	builting(t_data *data, int i, int index)
{
	int	size;

	size = i;
	while (data->par_line[++size])
	{
		if(full_detector(data, data->par_line[size]) > 0)
			break ;
	}
	size -= i;
	data->built.args = size;
	data->built.builtin[index] = (char **)malloc((size + 1) * sizeof(char *));
	data->built.builtin[index][size] = NULL;
	size = 0;
    while (data->par_line[i])
	{
		if (full_detector(data, data->par_line[i]) < 1)
			built_builting(data, size, index);
		else if(full_detector(data, data->par_line[i]) == 1 &&  size == 0)
			built_builting(data, i, index);
		else
			break ;
		i++;
		size++;
    }
}

void	built_builting(t_data *data, int i, int index)
{
	int	len;
	
	len = len_str(data->par_line[i]) + 1;
	data->built.builtin[index][i] = (char *)malloc(len * sizeof(char));
	data->built.builtin[index][i][len - 1] = 0;
	len = -1;
	while (data->par_line[i][++len])
	    data->built.builtin[index][i][len] = data->par_line[i][len];
}