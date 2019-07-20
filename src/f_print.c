/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:34:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/20 22:17:01 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*get_printf_str(int max_len)
{
	char *str;
	char *tbf1;
	char *tbf2;

	tbf1 = ft_itoa(max_len + 1);
	tbf2 = ft_strjoin("%-", tbf1);
	str = ft_strjoin(tbf2, "s");
	free(tbf1);
	free(tbf2);
	return (str);
}

void	init_table(t_node ****table, int cols, int lines)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (i < lines)
	{
		j = 0;
		while (j < cols + 1)
			(*table)[i][j++] = NULL;
		i++;
	}
}

t_node	***create_tab(t_node *all, t_info **info)
{
	int		cols;
	int		lines;
	t_node	***table;
	int		i;
	t_node	*tracker;

	i = 0;
	cols = get_width() / ((*info)->max_len + 1);
	lines = ((*info)->list_len / cols) + (((*info)->list_len % cols) != 0);
	table = (t_node***)malloc(lines * sizeof(t_node**));
	while(i < lines)
		table[i++] = (t_node**)malloc((cols + 1) * sizeof(t_node*));
	init_table(&table, cols, lines);
	i = -1;
	tracker = all;
	(*info)->lines_tbp = lines;
	(*info)->cols_tbp = cols;
	while (++i < ((*info)->list_len))
	{
		table[i % lines][i / lines] = tracker;
		tracker = tracker->next;
	}

	return(table);
}

void	free_tab(t_node ***table, int lines)
{
	int i;

	i = 0;
	while (i < lines)
		free(table[i++]);
	free(table);
}

void	f_print(t_node *head, t_info *info)
{
	char	*str;
	t_node	***table;
	int		i;
	int		j;

	str = get_printf_str(info->max_len);
	table = create_tab(head, &info);
	i = 0;

	while(i < info->lines_tbp)
	{
		j = 0;
		while(table[i][j + 1] != NULL)
		{
			print_color(table[i][j]->type, table[i][j]->perm);
			printf(str, table[i][j++]->name);
			print_color(0, 0);
		}
		print_color(table[i][j]->type, table[i][j]->perm);
		printf("%s\n",table[i][j]->name);
		print_color(0, 0);
		i++;
	}
	free(str);
	free_tab(table, info->lines_tbp);
	printf("\n");
}
