/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 06:49:28 by anfreire          #+#    #+#             */
/*   Updated: 2022/11/11 02:18:38 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	brain(t_data *data)
{
	int	i;

	i = 0;
	if (data->line == NULL || data->line[0] == '\0')
		return ;
	while (data->par_line[++i])
	{
		if (builtin_detector (data, data->par_line[i]) >= 0)
		{
			parse_builtin(data, i, data->built.b_counter);
			exec_builtin(data, i);
			data->built.b_counter++;
		}
		else if (cmd_detector(data, data->par_line[i]) == 1 && \
		data->paths.p_str != NULL)
		{
			printf("i %d\n", i);
			run_command(data, data->cmd.c_counter);
			data->cmd.c_counter++;
		}
		i = walk_till_pipe(data, i) - 1;
		if (i < 0)
			break ;
		printf("i %d\n", i);
	}
}

int	walk_till_pipe(t_data *data, int i)
{
	int	len;

	len = 0;
	while (data->par_line[len])
		len++;
	if (len <= i + 1)
		return (-1);
	else
	{
		while (data->par_line[++i])
		{
			if (builtin_detector(data, data->par_line[i]) >= 0)
				break ;
			else if (cmd_detector(data, data->par_line[i]) == 1 && \
			data->paths.p_str != NULL)
				break ;
		}
	}
	printf("len %d i %d \n", len, i);
	if (i == len)
		return (-1);
	return (i);
}

void	parse_cmds(t_data *data)
{
	int	i;
	int	cmds;

	i = -1;
	cmds = data->cmd.cmd_nbr + 1;
	while (++i < data->cmd.cmd_nbr)
	{
		if (pipe(data->ids.pfd[i]) != 0)
			return ;
	}
	i = 0;
	while (--cmds > 0)
	{
		parse_cmd (data, i);
		i++;
	}
}

void	starting(t_data *data, char *envp[])
{
	signal (SIGQUIT, sig_ignore);
	signal (SIGINT, sig_handler);
	get_envp (data, envp);
	data->line = NULL;
	data->andre.exit = 0;
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
