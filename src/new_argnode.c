/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:45:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/07 19:27:34 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_args	*new_argnode(char *arg_name)
{
	t_args		*arg;
	struct stat	*inf;

	inf = (struct stat*)malloc(sizeof(struct stat));
	if(!(arg = (t_args*)malloc(sizeof(t_args))))
	return (NULL);
	arg->name = arg_name;
	arg->previous = NULL;
	arg->next = NULL;
	lstat(arg_name, inf);
	arg->size = inf->st_blksize;
	arg->time = inf->st_mtime;
	free(inf);
	return(arg);
}
