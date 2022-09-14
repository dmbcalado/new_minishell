/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:15:55 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/10 02:35:40 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// built-in that performs the function of export in our own
// environment.
void	export(t_data *data, int index)
{
	if(data->built.args == 1)
		export_env (data);
	else if(data->built.args == 2)
		export_var (data, data->built.builtin[index][1]);
}

void	export_var(t_data *data, char *str)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (data->envp[i])
		i++;
	new_envp = (char **)malloc((i + 2) * sizeof(char *));
	new_envp[i + 1] = NULL;
	i = -1;
	while (data->envp[++i])
	{
		new_envp[i] =add_estr(data, i);
		free(data->envp[i]);
	}
	new_envp[i] = add_str(str);
	free(data->envp);
	data->envp = new_envp;
}

void	export_env(t_data *data)
{
	int	len;
	int	counter;
	int	*smal;
	
	len = 0;
	counter = -1;
	while(data->envp[len])
		len++;
	smal = (int *)malloc(len * sizeof(int));
	while(++counter < len)
		smal[counter] = -1;
	counter = -1;
	while(++counter < len)
		smal[counter] = get_next(data, smal);
	counter = -1;
	while(++counter < len)
		printf("declare -x %s\n", data->envp[smal[counter]]);
	free(smal);
}

int	get_next(t_data *data, int *smal)
{
	int i;
	int	j;
	int	s;

	s = 0;
	i = -1;
	while(smal[++i] >= 0)
	{
		if (find_in_list(smal, i) < 0)
			s++;
		else
			break ;
	}
	while(data->envp[++i] != NULL)
	{
		j = -1;
		while (data->envp[i][++j] != 0)
		{
			if (data->envp[i][j] < data->envp[s][j])
			{
				if (find_in_list(smal, i) >= 0)
				{
					s = i;
					break ;
				}
			}
			else if (data->envp[i][j] == data->envp[s][j] && i != s)
				continue ;
			else
				break ;
		}
	}
	return(s);
}

int	find_in_list(int *smal, int i)
{
	int	index;

	index = -1;
	while(smal[++index] >= 0)
	{
		if (smal[index] == i)
			return(-1);
	}
	return (index);
	
	
}

// built-in that performs the function of unset in our own
// environment.

