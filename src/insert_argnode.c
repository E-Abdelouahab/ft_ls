/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_argnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:14:08 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/27 16:25:19 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_func	get_function(int options)
{

	return(NULL);
}

void	insert_argnode(t_args **head, t_info *info, char *name)
{
	t_args *new_node;
	t_args *current;
	t_func function;

	new_node = new_argnode(name);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	function = get_function(info->flags);

//if new_node has to be inserted at the beggining of the list 
	//if (strcoll(path, (*head)->path) < 0)
	if (function((long)a, (long)b) < 0)
	{
		new_node->next = *head;
		new_node->next->previous = new_node;
		*head = new_node;
	}
	else
	{
		{
			current = *head;
			while (current->next != NULL && function(current->next->name, 
				new_node->name) < 0)
				current = current->next;
			new_node->next = current->next; 
			if (current->next != NULL)
				new_node->next->previous = new_node;
			current->next = new_node;
			new_node->previous = current;
		}
	}
}
