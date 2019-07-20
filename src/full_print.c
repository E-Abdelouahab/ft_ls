/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:10:44 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/20 22:27:07 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	get_time(time_t m_time)
{
	time_t	act_time;
	char	*tbf;

	act_time = time(NULL);
	if ((act_time - 15552000) > m_time)
	{
		tbf = ft_strsub(ctime(&m_time), 4, 7);
		printf("%s ", tbf);
		free(tbf);
		tbf = ft_strsub(ctime(&m_time), 20, 5);
		printf("%d  ", ft_atoi(tbf));
		free(tbf);
	}
	else
	{
		tbf = ft_strsub(ctime(&m_time), 4, 12);
		printf("%s  ", tbf);
		free(tbf);
	}
}

void	readable(off_t size)
{
	double	temp;
	int i = 0;
	char units[5];

	units[0] = 'B';
	units[1] = 'K';
	units[2] = 'M';
	units[3] = 'G';
	units[4] = 'T';
	temp = (double)size;
	while (temp> 1024.)
	{
		temp = temp / 1024.;
		i++;
	}
	printf("%8.1lf%-5c ", temp, units[i]);
}

long	get_total(t_node *head)
{
	long	total;

	total = 0;
	while(head)
	{
		total += head->blk_size;
		head = head->next;
	}
	return (total);
}

void	print_size(off_t size, int perms)
{
	if(perms & FLAG_H)
		readable(size);
	else
		printf("%10lld ", size);
}

void	full_print(t_node *head, t_info *info)
{
	t_node	*current;
	long	total;
	current = head;
	info->tracker = 0;
	if(info->print_total == 1)
	{
		total = get_total(current);
		printf("total %ld\n", total);
	}
	full_print_node(head, info);
	printf("\n");
}
