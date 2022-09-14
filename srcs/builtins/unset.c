/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:17:20 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/09 22:17:40 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	unset(t_data *data, char *str)
{
	int		i;
	int		j;
	int		flag;
	char	**new_envp;

	j = 0;
	flag = 0;
	i = env_var_detector(data, str);
	printf("i %d\n", i);
	if (i >= 0)
	{
		while (data->envp[j])
			j++;
		new_envp = (char **)malloc(j * sizeof(char *));
		new_envp[j - 1] = NULL;
		j = -1;
		while(data->envp[++j])
		{
			if (j != i)
				new_envp[j - flag] = selection(data, j);
			else
				flag = 1;
			free(data->envp[j]);
		}
		free(data->envp);
		data->envp = new_envp;
	}
}

char	*selection(t_data *data, int j)
{
	int		len;
	char	*str;


	len = len_str(data->envp[j]);
	str = (char *)malloc((len + 1) * sizeof(char));
	str[len] = 0;
	len = -1;
	while(data->envp[j][++len])
		str[len] = data->envp[j][len];
	return (str);
}


int	env_var_detector(t_data *data, char *str)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (data->envp[++i])
	{
			j = -1;
			len = len_str(data->envp[i]);
			while(str[++j] && j < len)
			{
				if(str[j] != data->envp[i][j])
					break;
			}
			len = len_str(str);
			if(j == len)
				return (i);
	}
	return (-1);
}