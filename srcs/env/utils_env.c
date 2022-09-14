/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:07:19 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/08 21:19:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*add_estr(t_data *data, int index)
{
	int	i;
	char *string;
	int	len;

	i = -1;
	len = len_str(data->envp[index]);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len] = '\0';
	while (data->envp[index][++i])
		string[i] = data->envp[index][i];
	return (string);
}

char	*add_str( char *str)
{
	int	i;
	int	len;
	char *string;

	i = -1;
	len = len_str(str);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len] = '\0';
	while(str[++i])
		string[i] = str[i];
	return(string);
}

int	equal(t_data *data, char *string, int index)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] != data->envp[index][i])
			return(0);
	}
	return (1);
}