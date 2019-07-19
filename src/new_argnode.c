/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:45:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/19 18:17:14 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

// char 	*get_link_path(char *arg_name, struct stat *inf)
// {
// 	char *buff;

// 	buff = (char*)falloc(sizeof(char) * inf->st_size + 1, 1, 0);
// 	readlink(arg_name, buff, inf->st_size);
// 	buff[inf->st_size] = '\0';
// 	return (buff);
// }

t_args	*new_argnode(char *arg_name)
{
	t_args		*arg;
	struct stat	*inf;

	inf = (struct stat*)falloc(sizeof(struct stat), 1, 0);
	if(!(arg = (t_args*)falloc(sizeof(t_args), 1, 0)))
		return (NULL);
	arg->name = ft_strdup(arg_name);
	arg->previous = NULL;
	arg->next = NULL;
	arg->size = inf->st_blksize;
	arg->m_time = inf->st_mtime;
	return(arg);
}
