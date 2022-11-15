/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 06:49:28 by anfreire          #+#    #+#             */
/*   Updated: 2022/11/15 00:06:24 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	walk_till_executable(t_data *data, int i)
{
	int	len;

	len = 0;
	while (data->par_line[len])
		len++;
	if (len <= i + 1)
		return (-1);
	else
	{
		while (data->par_line && data->par_line[++i])
		{
			if (builtin_detector(data, data->par_line[i]) >= 0)
				break ;
			else if (cmd_detector(data, data->par_line[i]) == 1 && \
			data->paths.p_str != NULL)
				break ;
		}
	}
	if (i == len)
		return (-1);
	return (i - 1);
}

void	brain(t_data *data)
{
	int	i;

	i = -1;
	if (data->line == NULL || data->line[0] == '\0')
		return ;
	while (data->par_line[++i])
	{
		if (builtin_detector (data, data->par_line[i]) >= 0)
		{
			parse_builtin(data, i, data->built.b_counter);
			exec_builtin(data, data->redir.r_counter, i);
			data->built.b_counter++;
		}
		else if (cmd_detector(data, data->par_line[i]) == 1 && \
		data->paths.p_str != NULL)
		{
			run_command(data, data->redir.r_counter, data->cmd.c_counter);
			data->cmd.c_counter++;
			data->redir.r_counter++;
		}
		i = walk_till_executable(data, i);
		if (i < 0)
			break ;
	}
	close_files(data);
}

void	close_files(t_data *data)
{
	int	i;
	int	size;

	i = -1;
	size = data->cmd.cmd_nbr + data->built.builtin_n;
	while (++i < size)
	{
		if (data->ids.inp_list[i] != STDIN_FILENO)
			close(data->ids.inp_list[i]);
		else
			close(data->ids.pfd[i][0]);
		if (data->ids.outp_list[i] != STDOUT_FILENO)
			close(data->ids.outp_list[i]);
		else
			close(data->ids.pfd[i][1]);
	}
	i = -1;
	while (++i < size)
		waitpid(data->ids.id[i], &data->andre.exit, 0);
	if (data->andre.exit > 256)
	{
		while (data->andre.exit > 256)
			data->andre.exit /= 256;
	}
	WEXITSTATUS(data->andre.exit);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc < 1 || *argv == NULL)
		return (0);
	starting(&data, envp);
	while (1)
	{
		get_line(&data);
		data.andre.args = 0;
		data.cmd.c_counter = 0;
		data.built.b_counter = 0;
		data.redir.r_counter = 0;
		data.redir.father_flag = 0;
		data.par_line = parse_line(&data);
		get_paths(&data);
		if (data.paths.p_str != NULL)
		{
			parse_alloc(&data);
			if (redirect(&data) < 0)
				continue ;
			parse_cmds(&data);
			brain(&data);
			free_line_info(&data);
		}
	}
	return (0);
}
