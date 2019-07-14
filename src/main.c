/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 23:33:05 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/13 20:15:07 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	read_function(t_node **head, t_info **info)
{
	if ((*info)->flags & FLAG_A)
		read_all(head, info, 0);
	else
		read_content(head, info, 0);
}

int main(int ac, char **av)
{
	t_args *args;
	t_info *info;
	t_node *head;
	t_args *args_;

	if (ac < 0)
		return 0;
	args = process_args(ac, av, &info);
	args_ = args;
	head = (t_node*)malloc(sizeof(t_node));
	while(args)
	{
		head->path = args->name;
		read_function(&head, &info);
		args = args->next;
	}
	falloc(0, 0, 0);
	return 0;
}
