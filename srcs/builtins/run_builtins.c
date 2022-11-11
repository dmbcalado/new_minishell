/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:35:12 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/10 20:01:55 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void    exec_builtin(t_data *data, int  i)
{
	int	jndex;

	jndex = builtin_detector(data, data->par_line[i]);
	if (jndex == 0)
		b_echo(data);
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
	else if (jndex == 6)
		run_minishell(data);
	else if (jndex == 7)
		exit_minishell(data);	
}