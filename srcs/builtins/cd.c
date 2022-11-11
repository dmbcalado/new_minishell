/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:02:05 by anfreire          #+#    #+#             */
/*   Updated: 2022/09/19 06:34:31 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	b_cd(t_data *data)
{
	int	i;
	
	i = 0;
	while (data->par_line[i])
		i++;
	if (i > 2)
	{
		printf("Minishell: cd: too many arguments\n");
		return;
	}
	else if (i == 1 || (strncmp(data->par_line[1], "~", 2) == 0 && i == 2))
	{
		chdir(getenv("HOME"));
		return ;
	}
	else if (chdir(data->par_line[1]) != 0)
	{
		printf("Minishell: cd: %s: No such file or directory\n", data->par_line[1]);
		return ;
	}
}
