/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 06:49:28 by anfreire          #+#    #+#             */
/*   Updated: 2022/09/14 23:39:45 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	brain(t_data *data)
{
	int	i;

	i = -1;
	data->built.b_counter = 0;
	if (data->line == NULL || data->line[0] == '\0')
		return ;
	while (data->par_line[++i])
	{
		if (builtin_detector (data, data->par_line[i]) > 0)
		{
			parse_builtin (data, i, data->built.b_counter);
			exec_builtin (data, i);
			data->built.b_counter++;
		}
		else if (cmd_detector (data, data->par_line[i]) == 1 && data->paths.p_str != NULL)
		{
			braining_cmds(data);
			return ;
		}
	}
}

void	braining_cmds(t_data *data)
{
	int	c;
	int cmds;
	
	c = 0;
	cmds = data->cmd.cmd_nbr;
	if(data->cmd.cmd_nbr == 1)
	{
		parse_cmd (data, 0);
		run_one_cmd (data, data->ids.inp_list[0], data->ids.outp_list[0]);
		return ;
	}
	else
	{
		while (cmds > 0)
		{
			parse_cmd (data, c);
			cmds--;
			c++;
		}
		pipes (data);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data data;

	if (argc < 1 || *argv == NULL)
		return (0);
	signal (SIGQUIT, sig_ignore);
	signal (SIGINT, sig_handler);
	get_envp (&data, envp);
	while (1)
	{
		get_line (&data);
		get_paths (&data);
		if(data.paths.p_str != NULL)
		{
			parse_alloc (&data);
			redirect(&data);
			brain (&data);
			free_line_info (&data);
		}
	}
	return (0);

}