/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:36:36 by anfreire          #+#    #+#             */
/*   Updated: 2022/10/10 20:04:22 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	echo_with_n_flag(t_data *data)
{
	int 	i;
	
	i = 1;
	while(data->andre.c_dbl_ptr[++i])
	{
		printf("%s", data->andre.c_dbl_ptr[i]);
		if (data->andre.c_dbl_ptr[i + 1])
			printf(" ");
	}
	i = -1;
	while(data->andre.c_dbl_ptr[++i])
		free(data->andre.c_dbl_ptr[i]);
	free(data->andre.c_dbl_ptr);
	data->andre.flag = 0;
}

void	b_echo(t_data *data)
{
	int 	i;
	char	flag[3];

	i = 0;
	flag[0] = '-';
	flag[1] = 'n';
	flag[2] = '\0';
	if (!data->par_line[1])
	{
		printf("\n");
		return ;
	}
	if (ft_strncmp(data->par_line[1], flag, 3) == 0)
	{
		data->andre.flag = 1;
		data->andre.args = 0;
		data->andre.c_dbl_ptr = parse_line(data);
	}
	else
	{
		while(data->par_line[++i])
		{
			printf("%s", data->par_line[i]);
			if (data->par_line[i + 1])
				printf(" ");
		}	
		printf("\n");
	}
}