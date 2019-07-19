/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_lnode_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:07:38 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/08 16:51:46 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int	insert_lnode_rev(const char* head_, const char* info_)
{
	t_node *new_node;
	t_node *current;
	t_node **head;
	t_info **info;

	head = (t_node**)head_;
	info = (t_info**)info_;
	current = *head;
	new_node = new_lnode(*info);
	if (*head == NULL)
	{
		*head = new_node;
		return (0);
	}
	if (sort_function(current, new_node, *info) < 0)
	{
		new_node->next = *head;
		new_node->next->previous = new_node;
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL && (sort_function(current->next, 
			new_node, *info) > 0))
			current = current->next;
		new_node->next = current->next;
		if (current->next != NULL)
			new_node->next->previous = new_node;
		current->next = new_node;
		new_node->previous = current;
	}
	return(0);
}
