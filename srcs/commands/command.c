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

void	run_command(t_data *data, int index, int cmd_i)
{
	if (acessing_cmd(data, cmd_i) != 1)
	{
		write(2, "Error on acessing the cmd\n", 27);
		return ;
	}
	data->ids.id[index] = fork();
	if (data->ids.id[index] == 0)
	{
		if (index == 0)
			piping_first(data, index);
		else if (index == data->cmd.cmd_nbr + data->built.builtin_n - 1) // esta aqui o segredo
			piping_last(data, index);
		else
		{
			redirecting_input(data, index);
			redirecting_output(data, index);
		}
		execve(data->paths.path_cmd[cmd_i], data->cmd.cmdx[cmd_i], data->envp);
	}
}
