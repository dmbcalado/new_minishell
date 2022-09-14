/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:29:28 by anfreire          #+#    #+#             */
/*   Updated: 2022/09/10 00:27:59 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../header.h"

// colects environment intrinsic to the computer and allocates
// to our own environment.

void	get_envp(t_data *data, char **envp)
{
	int		i;
	int		j;

	i = 0;
	while (envp[i])
		i++;
	data->envp = (char **)malloc((i + 1) * sizeof(char *));
	data->envp[i] = NULL;
	i = -1;
	while (envp[++i] != NULL)
	{
		j = 0;
		while(envp[i][j])
			j++;
		data->envp[i] = (char *)malloc((j + 1) * sizeof(char));
		data->envp[i][j] = '\0';
		j = -1;
		while(envp[i][++j] != 0)
			data->envp[i][j] = envp[i][j];
	}
}

// built-in that performs the function of env in our own
// environment.

void	env(t_data *data)
{
	int	i;

	i = -1;
	while (data->envp[++i])
		printf("%s\n",data->envp[i]);
}