/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:39:32 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/14 23:24:00 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	parse_redirec (t_data *data, int i)
{
	if (data->par_line[i][0] == data->redir.redir_lib[1]) // <
	{
		if (data->par_line[i][1] == 0)
			extract_input(data, i + 1, data->redir.input_c, 1);
		else if (data->par_line[i][0] == data->redir.redir_lib[1]) // <<
			extract_input(data, i + 1, data->redir.heredoc_c, 2);
	}
	if (data->par_line[i][0] == data->redir.redir_lib[2]) // >
	{
		if (data->par_line[i][1] == 0)
			extract_input(data, i + 1, data->redir.output_c, 1);
		else if (data->par_line[i][0] == data->redir.redir_lib[2]) // >>
			extract_input(data, i + 1, data->redir.append_c, 2);
	}
}

void	extract_input(t_data *data, int i, int index, int flag)
{
	int	j;

	j = 0;
	if (flag == 1)
	{
		while (data->par_line[i][j])
			j++;
		data->redir.input[index] = (char *)malloc((j + 1) * sizeof(char));
		data->redir.input[index][j] = 0;
		j = -1;
		while (data->par_line[i][++j])
			data->redir.input[index][j] = data->par_line[i][j];
		printf("input: %s\n", data->redir.input[index]);
		data->redir.input_c++;
	}
	else if (flag == 2)
	{
		while (data->par_line[i][j])
			j++;
		data->redir.heredoc[index] = (char *)malloc((j + 1) * sizeof(char));
		data->redir.heredoc[index][j] = 0;
		j = -1;
		while (data->par_line[i][++j])
			data->redir.heredoc[index][j] = data->par_line[i][j];
		printf("heredoc: %s\n", data->redir.input[index]);
		data->redir.heredoc_c++;
	}
}

void	extract_output(t_data *data, int i, int index, int flag)
{
	int	j;

	j = 0;
	if (flag == 1)
	{
		while (data->par_line[i][j])
			j++;
		data->redir.output[index] = (char *)malloc((j + 1) * sizeof(char));
		data->redir.output[j] = 0;
		j = -1;
		while (data->par_line[i][++j])
			data->redir.output[index][j] = data->par_line[i][j];
		printf("output: %s\n", data->redir.output[index]);
		data->redir.output_c++;
	}
	else if (flag == 2)
	{
		while (data->par_line[i][j])
			j++;
		data->redir.append[index] = (char *)malloc((j + 1) * sizeof(char));
		data->redir.append[index][j] = 0;
		j = -1;
		while (data->par_line[i][++j])
			data->redir.append[index][j] = data->par_line[i][j];
		printf("append: %s\n", data->redir.input[index]);
		data->redir.append_c++;
	}
}