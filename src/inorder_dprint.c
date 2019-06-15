/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preorder_dprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:31:49 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 20:06:20 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void inorder_dprint(t_node *node) 
{
	if (node == NULL)
		return;

	inorder_dprint(node->left);
	printf(ANSI_COLOR_BLUE " %s \n" ANSI_COLOR_RESET, node->name);
	inorder_dprint(node->right);
}
