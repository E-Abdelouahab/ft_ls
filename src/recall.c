/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:52:22 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 23:15:16 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void recall(t_node *node) 
{
	printf("recall %s : \n", node->name);
	if (node == NULL)
		return;

	if (node->left != NULL)
		recur(node->left);

		recur(node);

	if (node->right != NULL)
		recur(node->right);
	

}
