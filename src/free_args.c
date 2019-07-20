/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:33:05 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/20 22:20:06 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	free_args(t_args *args)
{
t_args	*tracker;

	tracker = args;
	if (tracker != NULL)
		args = tracker->next;
	while (tracker != NULL)
	{
		free(tracker->name);
		free(tracker);
		tracker = args;
		if (tracker != NULL)
			args = tracker->next;
	}
}