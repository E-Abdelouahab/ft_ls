/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 03:39:51 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/12 13:21:00 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_node		*new_node(char *path) 
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(node));
	node->name = path;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	// new node is initially added at leaf 
	return(node);
}
