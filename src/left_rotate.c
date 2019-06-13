/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 05:15:51 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/05/15 05:29:39 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node		*left_rotate(t_node *x) 
{
	t_node *y;
	t_node *T2;

	y = x->right;
	T2 = y->left;
	// Perform rotation
	y->left = x;
	x->right = T2;
	//  Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}
