/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:51:25 by anfreire          #+#    #+#             */
/*   Updated: 2022/08/29 19:12:15 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	exit_shell(t_data *data)
{
	if (!data->line || !ft_strncmp(data->line, "exit", 5))
		exit_shell_sig(1);
}

void	exit_shell_sig(int sig)
{
	if (sig == 1)
		printf("exit\n");
	exit(0);
}