/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 22:55:52 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/20 00:51:23 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	process_args(int ac, char **av)
{
	int		options;
	int		first_item;
	t_node	*head;

	head = NULL;
	first_item =  get_options(ac, av, &options);
	while (first_item < ac)
	{
	insert_lnode(&head, av[first_item], av[first_item], 0);
	if ((options & FLAG_A) && (options & FLAG_RCAP))
		read_all(&head, 0);
	else if (!(options & FLAG_A) && (options & FLAG_RCAP))
		read_content(&head, 0);
	first_item++;
	}
}
