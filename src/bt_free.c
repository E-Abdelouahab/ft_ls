/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:21:23 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/12 22:22:57 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void free_tree(t_node *node)
{
	if (node != NULL)
	{
		free_tree(node->right);
		free(node->name); //if data was heap allocated, need to free it
		free_tree(node->left);
		free(node);
	}
}
