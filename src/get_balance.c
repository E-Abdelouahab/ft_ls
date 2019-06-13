/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 05:23:38 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/05/15 05:30:20 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int get_balance(t_node *node)
{
	if (node == NULL) 
		return 0; 
	return height(node->left) - height(node->right); 
} 
