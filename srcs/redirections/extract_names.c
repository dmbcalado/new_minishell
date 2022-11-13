/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:02:23 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/13 03:42:41 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	extract_input(t_data *data, int index, int i)
{
	int	j;

	j = 0;
	while (data->par_line[i][j])
		j++;
	free(data->redir.input[index]);
	data->redir.input[index] = (char *)malloc((j + 1) * sizeof(char));
	data->redir.input[index][j] = 0;
	j = -1;
	while (data->par_line[i][++j])
		data->redir.input[index][j] = data->par_line[i][j];
}

void	extract_hdockey(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->par_line[i][j])
		j++;
	data->redir.hdoc_key = (char *)malloc((j + 1) * sizeof(char));
	data->redir.hdoc_key[j] = 0;
	j = -1;
	while (data->par_line[i][++j])
		data->redir.hdoc_key[j] = data->par_line[i][j];
}

void	extract_output(t_data *data, int index, int i)
{
	int	j;

	j = 0;
	while (data->par_line[i][j])
			j++;
	free(data->redir.output[index]);
	data->redir.output[index] = (char *)malloc((j + 1) * sizeof(char));
	data->redir.output[index][j] = 0;
	j = -1;
	while (data->par_line[i][++j])
		data->redir.output[index][j] = data->par_line[i][j];
}
