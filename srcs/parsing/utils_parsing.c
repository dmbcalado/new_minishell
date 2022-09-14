/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:59:41 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/10 02:41:47 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"
// -----------------------------------------------------------------------------

// Function function that compares the command with another string. ex: ls.

// -----------------------------------------------------------------------------

int	compare(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
	{
		if (s1[i] != s2[i] && s2[i] != s1[i] - 32)
			return (i);
	}
	return (-2);
}

// -----------------------------------------------------------------------------

// Function counts how many paths.

// -----------------------------------------------------------------------------

int	how_many_paths(char const *s, char c)
{
	int	i;
	int	flag;
	int	how_many;

	i = 0;
	flag = 0;
	how_many = 0;
	while (s[i] != '\0')
	{
		while (!(s[i] == '\0' || s[i] == c))
		{
			i++;
			flag = 1;
		}
		while (s[i] == c)
			i++;
		if (flag == 0)
			continue ;
		how_many++;
		if (s[i - 1] == '\0')
			break ;
	}
	return (how_many);
}

// -----------------------------------------------------------------------------

// Function returns the size of the full path to the executable file.

// -----------------------------------------------------------------------------
int	p_size(t_data *data, char* str, int i_p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->paths.paths[i_p][i])
        i++;
	while (str[j])
        j++;
	return(i + j);
}

int	path_size(t_data *data, int index, int i_p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->paths.paths[i_p][i])
        i++;
	while (data->cmd.cmdx[index][0][j])
        j++;
	return(i + j);
}

void	stringcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

// -----------------------------------------------------------------------------
// This function creates the builtins list to check if its a built in.
// -----------------------------------------------------------------------------

void	create_lists(t_data *data)
{
	data->built.builtins = (char **)malloc(8 * sizeof(char *));
	data->redir.redir_lib = (char *)malloc(4 * sizeof(char));
	get_str(data, "echo", 0);
	get_str(data, "pwd", 1);
	get_str(data, "env", 2);
	get_str(data, "export", 3);
	get_str(data, "unset", 4);
	get_str(data, "cd", 5);
	get_str(data, "pwd", 6);
	data->built.builtins[7] = NULL;
	data->redir.redir_lib[3] = 0;
	data->redir.redir_lib[0] = '|';
	data->redir.redir_lib[1] = '<';
	data->redir.redir_lib[2] = '>';
	data->ids.in_fd = STDIN_FILENO;
	data->ids.out_fd = STDOUT_FILENO;
}

void	get_str(t_data *data, char *str, int index)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	data->built.builtins[index] = (char *)malloc((i + 1) * sizeof(char));
	data->built.builtins[index][i] = 0;
	i = -1;
	while(str[++i] != 0)
		data->built.builtins[index][i] = str[i];
}