/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 03:39:51 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 19:46:51 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node		*new_node(char *name, char *path) 
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->name = name;
	node->path = path;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}
