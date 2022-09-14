/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:22:28 by anfreire          #+#    #+#             */
/*   Updated: 2022/08/29 18:52:26 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

/* *************************************************************************** */
/*							 Ctrl-C - SIGINT								   */
/*							 Ctrl-\ - SIGQUIT								   */
/*				 source: https://www.computerhope.com/unix/signals.htm         */
/* *************************************************************************** */
void    sig_handler(int signum)
{
    if (signum == SIGINT)
    {
		rl_on_new_line();
        rl_redisplay();
        printf("^C\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		printf("\n");
		rl_replace_line("[1]+  Stopped", 13);
		rl_redisplay();
	}
}

void	sig_ignore(int	signum)
{
	if (signum == SIGQUIT)
	{
		rl_on_new_line();
        rl_redisplay();
	}
}
