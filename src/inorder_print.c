/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preorder_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:18:28 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 20:05:28 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void inorder_print(t_node *node) 
{
	if (node == NULL)
		return;

	inorder_print(node->left);
	printf(" %s \n", node->name);
	inorder_print(node->right);
}
