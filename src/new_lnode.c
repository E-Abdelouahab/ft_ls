/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:47:09 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/05 15:39:51 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node *new_lnode(t_info *info)
{
	t_node	*node;

	if(!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->path = info->path_tbi;
	node->name = info->name_tbi;
	node->type = info->type_tbi;
	node->previous = NULL;
	node->next = NULL;

	return(node);
}
