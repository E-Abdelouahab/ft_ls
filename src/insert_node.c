/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:46:22 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 19:46:32 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node	*insert_node(t_node *node, char *name, char *path)
{
	if (node == NULL)
		return(new_node(name, path));

	if (strcoll(name, node->name) < 0)
		node->left = insert_node(node->left, name, path);

	else if (strcoll(name, node->name) > 0)
		node->right = insert_node(node->right, name, path);

	else
		return node;

	// printf(" name : %s \n", node->name);

	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = get_balance(node);

	if (balance > 1 && (strcoll(name, node->left->name) < 0))
		return right_rotate(node);

	if (balance < -1 && (strcoll(name, node->right->name) > 0))
		return left_rotate(node);

	if (balance > 1 && (strcoll(name, node->left->name) > 0))
	{
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	if (balance < -1 && (strcoll(name, node->right->name) < 0))
	{
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}
	return node;
}
