/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_lnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 23:52:24 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/18 20:02:13 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	insert_lnode(t_node **head, char *path, char *name, int type)
{
	t_node *new_node;
	t_node *current;

	new_node = new_lnode(path, name, type);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

//if new_node has to be inserted at the beggining of the list 
	if (strcoll(path, (*head)->path) < 0)
	{
		new_node->next = *head;
		new_node->next->previous = new_node;
		*head = new_node;
	}
	else
	{
		{
			current = *head;
			while (current->next != NULL && strcoll(current->next->path, 
				new_node->path) < 0)
				current = current->next;
			new_node->next = current->next; 
			if (current->next != NULL)
				new_node->next->previous = new_node;
			current->next = new_node;
			new_node->previous = current;
		}
	}
}
