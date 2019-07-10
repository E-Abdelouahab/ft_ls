/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:47:09 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/10 22:13:04 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node *new_lnode(t_info *info)
{
	t_node	*node;
	struct stat *inf;

	inf = (struct stat*)malloc(sizeof(struct stat));
	if(!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->path = get_dname(info->path_tbi, info->name_tbi);
	node->name = info->name_tbi;
	node->type = info->type_tbi;
	node->previous = NULL;
	node->next = NULL;
	lstat(node->path, inf);
	node->size = inf->st_size;
	node->time = inf->st_mtime;
	free(inf);
	return(node);
}
