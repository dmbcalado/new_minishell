/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:14:03 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/09 13:50:10 by dmendonc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	free_cmds(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->paths.path_cmd[++i])
		free(data->paths.path_cmd[i]);
	free(data->paths.path_cmd);
	i = -1;
	while (data->cmd.cmdx[++i])
	{
		j = -1;
		while (data->cmd.cmdx[i][++j])
			free(data->cmd.cmdx[i][j]);
		free(data->cmd.cmdx[i]);
	}
	free(data->cmd.cmdx);
	i = -1;
	while (data->ids.pfd[++i])
		free(data->ids.pfd[i]);
	free(data->ids.pfd);
	i = -1;
	free(data->ids.id);
	data->ids.in_fd = STDIN_FILENO;
	data->ids.out_fd = STDOUT_FILENO;
}

void	free_line_info(t_data *data)
{
	int	i;

	i = -1;
	if (data->cmd.cmd_nbr > 0)
		free_cmds(data);
	while (data->par_line[++i])
		free (data->par_line[i]);
	free(data->par_line);
	free_builtins(data);
	free(data->redir.redir_lib);
	i = -1;
	while (data->paths.paths[++i])
		free (data->paths.paths[i]);
	free (data->paths.paths);
	free (data->paths.p_str);
	i = -1;
	while(data->redir.input[++i])
		free(data->redir.input[i]);
	free(data->redir.input);
	i = -1;
	while (data->redir.output[++i])
		free (data->redir.output[i]);
	free (data->redir.output);
	free (data->ids.inp_list);
	free (data->ids.outp_list);
}

void	free_builtins(t_data *data)
{
	int	i;
	int	j;

	if (data->built.builtin_n > 0)
	{
		i = -1;
		while (data->built.builtin[++i])
		{
			j = -1;
			while (data->built.builtin[i][++j])
				free (data->built.builtin[i][j]);
			free (data->built.builtin[i]);
		}
		free (data->built.builtin);
	}
	i = -1;
	while (data->built.builtins[++i])
		free (data->built.builtins[i]);
	free (data->built.builtins);
}
