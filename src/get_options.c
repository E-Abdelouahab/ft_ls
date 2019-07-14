/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:46:31 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/14 13:23:20 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int in_str(char c, char *flag_str)
{
	int i;

	i = 0;
	while (flag_str[i])
	{
		if (flag_str[i] == c)
			return (i);
		i++;
	}
	return(-1);
}

int get_options(int argc, char **argv, t_info **info)
{
	int			i;
	int			j;
	int			checker;

	i = 1;
	(*info)->flags = 0;
	if(argc != 1)
	{
		while (i < argc)
		{
			if (check_valid_opt(argv[i]) == 2)
				return (i + 1);
			if (check_valid_opt(argv[i]) == 0)
				return (i);
			if (check_valid_opt(argv[i]) == 1)
			{
				j = 1;
				while (argv[i][j])
				{
					if ((checker = in_str(argv[i][j], FLAGS_STR)) >= 0)
					{
						if ((1 << checker) & FLAG_SCAP && !((*info)->flags & FLAG_T))
							(*info)->flags |= FLAG_SCAP;
						else if((1 << checker) & FLAG_T && !((*info)->flags & FLAG_SCAP))
							(*info)->flags |= FLAG_T;
						else
							(*info)->flags |= (1 << checker);
					}
					else
						usage_error(argv[i][j]);
					j++;
				}
			}
			i++;
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
