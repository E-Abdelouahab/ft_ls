/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:47:09 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/18 20:01:39 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node *new_lnode(char *path, char *name, int type)
{
	t_node	*node;

	if(!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->path = path;
	node->name = name;
	node->type = type;
	node->previous = NULL;
	node->next = NULL;

	return(node);
}
