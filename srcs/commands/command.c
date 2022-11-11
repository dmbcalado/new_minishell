/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:40 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/09 14:07:02 by dmendonc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	run_command(t_data *data, int index)
{
	if (acessing_cmd(data, index) != 1)
	{
		write(2, "Error on acessing the cmd\n", 27);
		return ;
	}
	else
		printf("%s\n", data->cmd.cmdx[index][0]);
	data->ids.id[index] = fork();
	if (data->ids.id[index] == 0)
	{
		run_child(data, index);
		execve(data->paths.path_cmd[index], data->cmd.cmdx[index], data->envp);
	}
	else
		run_father(data, index);
}

void	run_child(t_data *data, int index)
{
	if (index == 0)
		piping_first(data, index);
	else if (index == data->cmd.cmd_nbr - 1)
		piping_last(data, index);
	else
	{
		redirecting_input(data, index);
		redirecting_output(data, index);
	}
}

void	run_father(t_data *data, int index)
{
	(void)index;

	/* while (data->redir.father_flag != 1000)
		data->redir.father_flag++; */
	waitpid(data->ids.id[index], &data->andre.exit, 0);
	if (data->andre.exit > 256)
	{
		while (data->andre.exit > 256)
		data->andre.exit /= 256;
	}
	WEXITSTATUS(data->andre.exit);
}

void	redirecting_input(t_data *data, int index)
{
	if (data->ids.inp_list[index] != STDIN_FILENO)
	{
		dup2(data->ids.inp_list[index], STDIN_FILENO);
		data->redir.input_c++;
	}
	else
	{
		close(data->ids.pfd[index - 1][1]);
		close(data->ids.pfd[index][0]);
		dup2(data->ids.pfd[index - 1][0], STDIN_FILENO);
	}
}

void	redirecting_output(t_data *data, int index)
{
	if (data->ids.outp_list[index] != STDOUT_FILENO)
	{
		dup2(data->ids.outp_list[index], STDOUT_FILENO);
		data->redir.output_c++;
	}
	else
	{
		close(data->ids.pfd[index - 1][1]);
		close(data->ids.pfd[index][0]);
		dup2(data->ids.pfd[index - 1][1], STDOUT_FILENO);
	}
}
