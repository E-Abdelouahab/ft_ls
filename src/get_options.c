/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:46:31 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/06 12:45:05 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int get_options(int argc, char **argv, t_info **info)
{
	int			i;

	i = 0;
	(*info)->flags = 0;
	while (i++ < argc)
	{
		if (check_valid_opt(argv[i]) == 2)
			return (i + 1);
		if (check_valid_opt(argv[i]) == 0)
			return (i);
		if (check_valid_opt(argv[i]) == 1)
		{
			if(if_char(argv[i], 'l'))
				(*info)->flags |= FLAG_L;
			if(if_char(argv[i], 'R'))
				(*info)->flags |= FLAG_RCAP;
			if(if_char(argv[i], 'a'))
				(*info)->flags |= FLAG_A;
			if(if_char(argv[i], 'r'))
				(*info)->flags |= FLAG_RLOW;
			if(if_char(argv[i], 't'))
			{
				if((*info)->flags & FLAG_SCAP)
				{
					(*info)->flags =| FLAG_ST;
					(*info)->flags &= ~FLAG_SCAP;
				}
				else if (!((*info)->flags & FLAG_ST || (*info)->flags & FLAG_TS))
					(*info)->flags |= FLAG_T;
			}
			if(if_char(argv[i], 'S'))
			{
				if((*info)->flags & FLAG_T)
				{
					(*info)->flags =| FLAG_TS;
					(*info)->flags &= ~FLAG_T;
				}
				else if (!((*info)->flags & FLAG_ST || (*info)->flags & FLAG_TS))
					(*info)->flags |= FLAG_S;
			}
		}
	}
	return (i);
}

// i is the index of the first non flag argument.

int check_valid_opt(char *str)
{
	if (str[0] == '-' && strcmp(str, "-") != 0 && strcmp(str, "--") != 0)
		return 1;
	else if (strcmp(str, "--") == 0)
		return 2;
	else
		return 0;
}

int if_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}
