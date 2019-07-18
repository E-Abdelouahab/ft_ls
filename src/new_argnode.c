/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:45:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/17 19:03:17 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char 	*get_link_path(char *arg_name, struct stat *inf)
{
	char *buff;

	buff = (char*)falloc(sizeof(char) * inf->st_size + 1, 1, 0);
	readlink(arg_name, buff, inf->st_size);
	buff[inf->st_size] = '\0';
	return (buff);
}

t_args	*new_argnode(char *arg_name, t_info *info)
{
	t_args		*arg;
	struct stat	*inf;

	inf = (struct stat*)falloc(sizeof(struct stat), 1, 0);
	if(!(arg = (t_args*)falloc(sizeof(t_args), 1, 0)))
	return (NULL);
	arg->name = ft_strdup(arg_name);
	arg->previous = NULL;
	arg->next = NULL;
	arg->option = 0;
	if (stat(arg_name, inf) == 0)
	{
		if((inf->st_mode & S_IFMT) == S_IFLNK)
		{
			if(info->flags & FLAG_L && stat(arg->name, inf) == 0)
				arg->option = 1;
			else
				arg->name = get_link_path(arg_name, inf);
		}
		else if (arg->option != 1)
		{
			if((inf->st_mode & S_IFMT) == S_IFDIR)
				arg->option = 0;
			else
				arg->option = 1;
		}
	}
	arg->size = inf->st_blksize;
	arg->m_time = inf->st_mtime;
	return(arg);
}
