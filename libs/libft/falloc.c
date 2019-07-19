/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   falloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:38:45 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/13 20:21:19 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*falloc(size_t size, int option, int tracker)
{
	static t_free *first;
	static t_free *last;

	if(tracker)
		first = NULL;
	if (option == 1)
	{
		if(first == NULL)
		{
			first = (t_free*)malloc(sizeof(t_free));
			last = first;
		}
		else
		{
			last->next = (t_free*)malloc(sizeof(t_free));
			last = last->next;
		}
		last->next = NULL;
		last->address = malloc(size);
		return(last->address);
		
	}
	else
	{
		last = first;
		first = last->next;
		while (last)
		{
			free(last->address);
			free(last);
			last = first;
			if (last != NULL)
				first = last->next;
		}
		first = NULL;
		last = NULL;
	}
	return(NULL);
}
