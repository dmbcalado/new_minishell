/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:34:10 by anfreire          #+#    #+#             */
/*   Updated: 2022/09/19 05:25:17 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	b_pwd(void)
{
	char buff[FILENAME_MAX];
	
	getcwd(buff, FILENAME_MAX);
	printf("%s\n", buff);
}