/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:54:26 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/12 15:55:03 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	starting(t_data *data, char *envp[])
{
	signal (SIGQUIT, sig_ignore);
	signal (SIGINT, sig_handler);
	get_envp (data, envp);
	data->line = NULL;
	data->andre.exit = 0;
}
