/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:35:12 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/14 23:22:56 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	g_exit;

void	exec_builtin(t_data *data, int index, int i)
{
	int	jndex;

	jndex = builtin_detector(data, data->par_line[i]);
	printf("BUILTIN %d\n", jndex);
	if (jndex < 6 && jndex >= 0)
	{
		data->ids.id[index] = fork();
		if (data->ids.id[index] == 0)
		{
			if (index == 0)
				piping_first(data, index);
			else if (index == data->cmd.cmd_nbr + data->built.builtin_n + 1)
				piping_last(data, index);
			else
			{
				redirecting_input(data, index);
				redirecting_output(data, index);
			}
			execve_builtin(data, jndex, i);
			exit(g_exit);
		}
	}
	else if (jndex == 6)
		run_minishell(data, index);
	else if (jndex == 7)
		exit_minishell(data);
}

void	execve_builtin(t_data *data, int jndex, int i)
{
	if (jndex == 0)
		b_echo(data, i);
	else if (jndex == 1)
		b_pwd();
	if (jndex == 2)
		env(data);
	else if (jndex == 3)
		export(data, data->built.b_counter);
	else if (jndex == 4)
		unset(data, data->par_line[1]);
	else if (jndex == 5)
		b_cd(data);
}
