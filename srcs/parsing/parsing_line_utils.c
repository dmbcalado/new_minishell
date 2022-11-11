/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:51:44 by anfreire          #+#    #+#             */
/*   Updated: 2022/10/28 00:08:12 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	trim_spaces(char *str) //removes spaces from beggining and end of str
{
	int	i;
	
	if (str[0] == ' ' && str[0])
	{
		while (str[0] == ' ' && str[0])
		{
			ft_memmove(&str[0], &str[1], ft_strlen(str));
		}
	}
	i = ft_strlen(str);
	if (str[i] == ' ' && str[i])
	{
		while (str[i] == ' ' && str[i])
		{
			str[i] = 0;
			i--;
		}
	}	
}

int	is_str_in_quotes(char *str, char c)// Returns 1 if index is a char as another occurence of the same char after
{
	if (str[0] == c && ft_strchr(&str[1], c) != NULL)
		return (1);
	else
		return (0);
}

static char	*empty_string(char *str)
{
	free(str);
	str = malloc(sizeof(char));
	str[0] = 0;
	return (str);
}

static char	*get_string_var(char *str, char *var)
{
	free(str);
	str = malloc(sizeof(char) * (ft_strlen(var) + 1));
	ft_strlcpy(str, var, ft_strlen(var) + 1);
	return (str);
}

char	*is_string_expandable(char *str, t_data *data)
{
	int		i;
	char	*var;
	char	exit[3];

	strncpy(exit, "$?", 2);
	exit[2] = 0;
	if (!strncmp(exit, str, ft_strlen(str)))
	{
		free(str);
		str = ft_itoa(data->andre.exit);
		return (str);
	}
	else if (str[0] == '$')
	{
		var = ft_substr(&str[1], 0, ft_strlen(str));
		i = env_var_detector(data, var);
		free(str);
		if (i == -1)
			var = empty_string(var);
		else
			var = get_string_var(var, strchr(data->envp[i], '=') + 1);
		return (var);
	}
	else
		return (str);
}