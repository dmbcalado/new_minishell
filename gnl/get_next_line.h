/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:32:58 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/22 20:46:19 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif
# include "./libft/libft.h"

//	UTILS :
int		search_for_size(const char *buffer, int chr);
int		search_for_bl(char *buffer);
char	*join_buffer(char *temporary, char *buff, int size);

//	MAIN :

char	*get_next_line(int fd);
#endif