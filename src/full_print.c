/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:10:44 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/13 23:12:46 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*get_time(time_t m_time)
{
	char	*r_time;
	char	*ret_time;

	r_time = ctime(&m_time);
	ret_time = ft_strsub(r_time, 4, 12);
	return(ret_time);
}

void	readable(off_t size)
{
	double	temp;
	int i = 0;
	char *buf;
	char *units[5];

	units[0] = "B";
	units[1] = "K";
	units[2] = "M";
	units[3] = "G";
	units[4] = "T";
	buf = (char*)falloc(sizeof(char*), 1, 1);
	temp = (double)size;
	while (temp> 1024.)
	{
		temp = temp / 1024.;
		i++;
	}
	printf("%8.1lf%-5s ", temp, units[i]);
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
	total = get_total(current);
	printf("total %ld\n", total);
	full_print_node(head, info);
	printf("\n");
}
