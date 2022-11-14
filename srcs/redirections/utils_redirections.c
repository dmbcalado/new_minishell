/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:13:18 by dmendonc          #+#    #+#             */
/*   Updated: 2022/11/14 17:26:04 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	reset_counters(t_data *data)
{
	data->redir.input_c = 0;
	data->redir.output_c = 0;
}

// -----------------------------------------------------------------------------
// This function will have the porpose to get the i for the last input, to the
// command index. example:
// (...) | < infile.txt grep porque < infile2.txt << infile.txt | (...)
//
// we want the i for infile.txt.
// -----------------------------------------------------------------------------

int	find_i_for_infile(t_data *data, int index)
{
	int	i;
	int	save;
	int	ind_c;

	i = -1;
	ind_c = -1;
	while (++ind_c <= index)
	{
		save = 0;
		while (data->par_line[++i] && redir_detector(data, data->par_line[i]) \
		!= 1)
		{
			if (redir_detector(data, data->par_line[i]) > 1)
			{
				if (redir_detector(data, data->par_line[i]) == 2)
					save = i;
				else if (redir_detector(data, data->par_line[i]) == 3)
					save = i;
			}
		}
	}
	return (save);
}

// -----------------------------------------------------------------------------
// This function will have the porpose to get the i for the last output, to the
// command index. example:
// (...) | grep porque >> output.txt > output2.txt | (...)
//
// we want the i for output2.txt.
// -----------------------------------------------------------------------------

int	find_i_for_outfile(t_data *data, int index)
{
	int	i;
	int	save;
	int	ind_c;

	i = -1;
	ind_c = -1;
	save = 0;
	while (++ind_c <= index)
	{
		while (data->par_line[++i] && \
		redir_detector(data, data->par_line[i]) != 1)
		{
			if (redir_detector(data, data->par_line[i]) > 1)
			{
				if (redir_detector(data, data->par_line[i]) >= 4)
					save = i;
			}
		}
	}
	return (save);
}
