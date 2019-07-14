/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:45:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/13 20:02:47 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_args	*new_argnode(char *arg_name)
{
	t_args		*arg;
	struct stat	*inf;

	inf = (struct stat*)falloc(sizeof(struct stat), 1, 1);
	if(!(arg = (t_args*)falloc(sizeof(t_args), 1, 1)))
	return (NULL);
	arg->name = ft_strdup(arg_name);
	arg->previous = NULL;
	arg->next = NULL;
	lstat(arg_name, inf);
	arg->size = inf->st_blksize;
	arg->m_time = inf->st_mtime;
	return(arg);
}
