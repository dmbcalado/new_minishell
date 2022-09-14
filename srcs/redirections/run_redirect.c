/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:31:48 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/14 23:49:51 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	redirect(t_data *data)
{
	int i;
	
	i = -1;
	data->redir.input_c = 0;
	data->redir.output_c = 0;
	data->redir.append_c = 0;
	data->redir.heredoc_c = 0;
	while (data->par_line[++i])
	{
		if (redir_detector(data, data->par_line[i]) > 0)
			parse_redirec(data, i);
	}
	if(data->redir.input_c == 0)
	{
		data->ids.inp_list = (int *)malloc(sizeof(int));
		data->ids.inp_list[0] = STDIN_FILENO;
	}
	else
		data->ids.inp_list = (int *)malloc(data->redir.input_c * sizeof(int));
	if(data->redir.output_c == 0)
	{
		data->ids.outp_list = (int *)malloc(sizeof(int));
		data->ids.outp_list[0] = STDOUT_FILENO;
	}
	else
		data->ids.outp_list = (int *)malloc(data->redir.output_c * sizeof(int));
	exec_redirect(data);
}

void	exec_redirect(t_data *data)
{
	int	j;

	j = 0;
	if (data->redir.input_n > 0)
	{
		while(j < data->redir.input_n)
		{
			data->ids.inp_list[j] = open (data->redir.input[j], O_RDONLY);
			if(data->ids.inp_list[j] < 0)
			{
				printf("Error: the file %s does not exist.", data->redir.input[j]);
				return ;
			}
			else
				printf("sucessefully opened %s\n\n", data->redir.input[j]);
			j++;
		}
	}
	j = 0;
	if (data->redir.output_n > 0)
	{
		while(j < data->redir.output_n)
		{
			data->ids.outp_list[j] = open(data->redir.input[j], O_CREAT | O_TRUNC | O_RDWR);
			if(data->ids.outp_list[j] < 0)
			{
				printf("Error: the file %s had issues on open().", data->redir.input[j]);
				return ;
			}
			else
				printf("sucessefully opened %s\n\n", data->redir.output[j]);
			j++;
		}
	}
}