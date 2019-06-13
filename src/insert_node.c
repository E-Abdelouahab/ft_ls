/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:46:22 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/12 22:07:17 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.  
t_node	*insert_node(t_node *node, char *name)  
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(new_node(name));

	if (strcoll(name, node->name) < 0)
		node->left = insert_node(node->left, name);
	else if (strcoll(name, node->name) > 0)
		node->right = insert_node(node->right, name);
	else // Equal keys are not allowed in BST
		return node;
  
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = get_balance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case  
	if (balance > 1 && (strcoll(name, node->left->name) < 0))
	return right_rotate(node);

	// Right Right Case
	if (balance < -1 && (strcoll(name, node->right->name) > 0))
		return left_rotate(node);

	// Left Right Case  
	if (balance > 1 && (strcoll(name, node->left->name) > 0))
	{
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	// Right Left Case
	if (balance < -1 && (strcoll(name, node->right->name) < 0))
	{
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
