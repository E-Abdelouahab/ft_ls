/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:05:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:07:15 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	free_nodes(t_node *nodes)
{
	t_node	*tracker;

	tracker = nodes;
	if (tracker != NULL)
		nodes = tracker->next;
	while (tracker != NULL)
	{
		free(tracker->name);
		free(tracker->path);
		free(tracker->owner);
		free(tracker->group);
		free(tracker);
		tracker = nodes;
		if (tracker != NULL)
			nodes = tracker->next;
	}
}
